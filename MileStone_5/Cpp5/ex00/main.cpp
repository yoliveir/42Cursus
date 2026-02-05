/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:06:36 by yurolive          #+#    #+#             */
/*   Updated: 2026/02/05 16:20:17 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

static void testValid()
{
    std::cout << "\n--- testValid ---\n";
    Bureaucrat a("Alice", 1);
    Bureaucrat b("Bob", 150);

    std::cout << a << "\n";
    std::cout << b << "\n";
}

static void testConstructorExceptions()
{
    std::cout << "\n--- testConstructorExceptions ---\n";

    try {
        Bureaucrat x("X", 0);
        std::cout << x << "\n";
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }

    try {
        Bureaucrat y("Y", 151);
        std::cout << y << "\n";
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }
}

static void testIncrementDecrement()
{
    std::cout << "\n--- testIncrementDecrement ---\n";

    try {
        Bureaucrat top("Top", 1);
        std::cout << top << "\n";
        std::cout << "Trying increment at grade 1...\n";
        top.incrementGrade(); // should throw
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }

    try {
        Bureaucrat low("Low", 150);
        std::cout << low << "\n";
        std::cout << "Trying decrement at grade 150...\n";
        low.decrementGrade(); // should throw
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }

    Bureaucrat mid("Mid", 42);
    std::cout << "\nStart: " << mid << "\n";
    mid.incrementGrade();
    std::cout << "After increment: " << mid << "\n";
    mid.decrementGrade();
    std::cout << "After decrement: " << mid << "\n";
}

static void testCopyAssign()
{
    std::cout << "\n--- testCopyAssign ---\n";

    Bureaucrat a("A", 10);
    Bureaucrat b("B", 50);

    std::cout << "Before assign:\n";
    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";

    b = a;
    std::cout << "After b = a:\n";
    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
}

int main()
{
    testValid();
    testConstructorExceptions();
    testIncrementDecrement();
    testCopyAssign();
    return 0;
}