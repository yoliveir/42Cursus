/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:12:07 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/12 16:12:09 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

RPN::RPN() {}

int RPN::evaluate(const std::string& expression)
{
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (token.size() == 1 && isdigit(token[0]))
        {
            _stack.push(token[0] - '0');
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");

            int b = _stack.top();
            _stack.pop();

            int a = _stack.top();
            _stack.pop();

            int result;

            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else
            {
                if (b == 0)
                    throw std::runtime_error("Error");
                result = a / b;
            }

            _stack.push(result);
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}