/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:25:13 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/09 16:25:15 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");

    std::string line;

    getline(file, line);

    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string price;

        getline(ss, date, ',');
        getline(ss, price);

        _database[date] = atof(price.c_str());
    }
}

bool BitcoinExchange::validDate(const std::string& date)
{
    if (date.size() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    return true;
}

bool BitcoinExchange::validValue(const std::string& value)
{
    double v = atof(value.c_str());

    if (v < 0)
        throw std::runtime_error("Error: not a positive number.");

    if (v > 1000)
        throw std::runtime_error("Error: too large a number.");

    return true;
}

double BitcoinExchange::getRate(const std::string& date)
{
    std::map<std::string, double>::iterator it = _database.lower_bound(date);

    if (it == _database.end() || it->first != date)
    {
        if (it == _database.begin())
            throw std::runtime_error("Error: no earlier date.");

        it--;
    }

    return it->second;
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;

    getline(file, line);

    while (getline(file, line))
    {
        try
        {
            std::stringstream ss(line);

            std::string date;
            std::string value;

            getline(ss, date, '|');
            getline(ss, value);

            date.erase(date.find_last_not_of(" ") + 1);
            value.erase(0, value.find_first_not_of(" "));

            if (!validDate(date))
                throw std::runtime_error("Error: bad input => " + date);

            validValue(value);

            double v = atof(value.c_str());
            double rate = getRate(date);

            std::cout << date << " => " << v << " = " << v * rate << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}