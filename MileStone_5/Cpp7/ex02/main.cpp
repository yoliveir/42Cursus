/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:16:50 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/05 15:16:52 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        std::cout << "Creating array of 5 ints\n";

        Array<int> a(5);

        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i * 2;

        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << std::endl;

        std::cout << "\nTesting copy constructor\n";

        Array<int> b(a);

        b[0] = 42;

        std::cout << "Original: " << a[0] << std::endl;
        std::cout << "Copy: " << b[0] << std::endl;

        std::cout << "\nTesting assignment operator\n";

        Array<int> c;
        c = a;

        c[1] = 99;

        std::cout << "Original: " << a[1] << std::endl;
        std::cout << "Assigned: " << c[1] << std::endl;

        std::cout << "\nTesting out of bounds\n";

        std::cout << a[10] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}