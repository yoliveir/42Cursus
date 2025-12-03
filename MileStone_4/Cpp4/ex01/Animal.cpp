/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:04:37 by yurolive          #+#    #+#             */
/*   Updated: 2025/12/02 15:04:44 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "[Animal] Constructor called\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "[Animal] Copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "[Animal] Copy assignment called\n";
    if (this != &other)
        type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] Destructor called\n";
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "[Animal] Generic animal sound\n";
}