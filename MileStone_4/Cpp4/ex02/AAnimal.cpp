/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:38:02 by yurolive          #+#    #+#             */
/*   Updated: 2025/12/02 15:38:59 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal") {
    std::cout << "[Animal] Constructor called\n";
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "[AAnimal] Copy constructor called\n";
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    std::cout << "[AAnimal] Copy assignment called\n";
    if (this != &other)
        type = other.type;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "[AAnimal] Destructor called\n";
}

std::string AAnimal::getType() const {
    return type;
}