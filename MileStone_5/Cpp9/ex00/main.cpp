/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:28:45 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/09 16:28:47 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange btc;

        btc.loadDatabase("data.csv");
        btc.processInput(argv[1]);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}