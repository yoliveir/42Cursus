/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:21:24 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/12 16:21:26 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; i++)
    {
        int n = std::atoi(argv[i]);

        if (n < 0)
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }

        vec.push_back(n);
        deq.push_back(n);
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    PmergeMe sorter;

    clock_t start = clock();
    sorter.sortVector(vec);
    clock_t end = clock();

    double vectorTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

    start = clock();
    sorter.sortDeque(deq);
    end = clock();

    double dequeTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : "
              << vectorTime << " us" << std::endl;

    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque : "
              << dequeTime << " us" << std::endl;
}