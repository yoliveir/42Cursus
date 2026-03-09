/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:50:32 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/09 15:50:34 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Span.hpp"

int main()
{
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\nTesting big span\n";

    Span big(10000);

    std::vector<int> numbers;

    for (int i = 0; i < 10000; i++)
        numbers.push_back(rand());

    big.addRange(numbers.begin(), numbers.end());

    std::cout << "Shortest: " << big.shortestSpan() << std::endl;
    std::cout << "Longest: " << big.longestSpan() << std::endl;
}