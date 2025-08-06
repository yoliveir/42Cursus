/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:54:01 by yurolive          #+#    #+#             */
/*   Updated: 2025/08/06 18:24:42 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //Equivalent of Printf
#include <iomanip> //Input/Output Manipulators
#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

void Zombie::announce( void )
{
     std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << ": Ha sido destruido 💀" << std::endl;
}