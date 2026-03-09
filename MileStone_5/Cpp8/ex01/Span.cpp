/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:48:51 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/09 15:48:52 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is full");

    _numbers.push_back(n);
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    std::vector<int> temp = _numbers;

    std::sort(temp.begin(), temp.end());

    int shortest = std::numeric_limits<int>::max();

    for (size_t i = 1; i < temp.size(); i++)
    {
        int diff = temp[i] - temp[i - 1];

        if (diff < shortest)
            shortest = diff;
    }

    return shortest;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}