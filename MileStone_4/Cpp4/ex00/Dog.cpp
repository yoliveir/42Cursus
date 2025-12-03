/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:33:18 by yurolive          #+#    #+#             */
/*   Updated: 2025/12/02 14:33:38 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other)
{
    Animal::operator=(other);
    std::cout << "Dog copy assignment called\n";
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!\n";
}