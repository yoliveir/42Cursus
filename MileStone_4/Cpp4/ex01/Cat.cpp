/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:10:53 by yurolive          #+#    #+#             */
/*   Updated: 2025/12/02 15:31:29 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
    type = "Cat";
    std::cout << "[Cat] Constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "[Cat] Copy constructor called\n";
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "[Cat] Copy assignment called\n";
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Brain* Cat::getBrain() const { return brain; }

Cat::~Cat()
{
    delete brain;
    std::cout << "[Cat] Destructor called\n";
}

void Cat::makeSound() const {
    std::cout << "🐱 Meow~\n";
}