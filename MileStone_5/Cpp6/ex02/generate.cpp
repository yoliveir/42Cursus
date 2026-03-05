/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:49:11 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/05 14:49:13 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    int r = std::rand() % 3;

    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}