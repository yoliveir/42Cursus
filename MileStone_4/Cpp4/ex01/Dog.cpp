/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:05:37 by yurolive          #+#    #+#             */
/*   Updated: 2025/12/02 15:30:40 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
    type = "Dog";
    std::cout << "[Dog] Constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "[Dog] Copy constructor called\n";
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] Copy assignment called\n";
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Brain* Dog::getBrain() const { return brain; }

Dog::~Dog()
{
    delete brain;
    std::cout << "[Dog] Destructor called\n";
}

void Dog::makeSound() const {
    std::cout << "🐶 Woof! Woof!\n";
}