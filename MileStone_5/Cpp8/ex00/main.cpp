/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:35:27 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/09 15:35:28 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> v;

        v.push_back(3);
        v.push_back(7);
        v.push_back(10);
        v.push_back(42);

        std::vector<int>::iterator it = easyfind(v, 10);

        std::cout << "Found: " << *it << std::endl;

        easyfind(v, 99);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTesting with list\n";

    try
    {
        std::list<int> l;

        l.push_back(1);
        l.push_back(2);
        l.push_back(3);

        std::list<int>::iterator it = easyfind(l, 2);

        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}