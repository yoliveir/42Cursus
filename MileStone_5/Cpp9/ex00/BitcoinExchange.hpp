/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:23:36 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/09 16:23:38 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
private:
    std::map<std::string, double> _database;

public:
    BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void processInput(const std::string& filename);

    bool validDate(const std::string& date);
    bool validValue(const std::string& value);

    double getRate(const std::string& date);
};

#endif