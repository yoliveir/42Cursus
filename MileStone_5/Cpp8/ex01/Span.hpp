/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:48:23 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/09 15:50:10 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <stdexcept>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int n);

    int shortestSpan();
    int longestSpan();

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        if (_numbers.size() + std::distance(begin, end) > _maxSize)
            throw std::runtime_error("Span is full");

        _numbers.insert(_numbers.end(), begin, end);
    }
};

#endif