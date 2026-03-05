/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:09:58 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/05 15:10:00 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        Array<int> numbers(5);

        for (unsigned int i = 0; i < numbers.size(); i++)
            numbers[i] = i * 10;

        std::cout << "Array contents:" << std::endl;

        for (unsigned int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << std::endl;

        std::cout << "\nTesting copy:" << std::endl;

        Array<int> copy = numbers;

        copy[0] = 999;

        std::cout << "Original: " << numbers[0] << std::endl;
        std::cout << "Copy: " << copy[0] << std::endl;

        std::cout << "\nTesting exception:" << std::endl;

        std::cout << numbers[10] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}