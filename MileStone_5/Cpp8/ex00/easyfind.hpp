/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:33:53 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/09 15:33:55 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw std::runtime_error("Value not found");

    return it;
}

#endif