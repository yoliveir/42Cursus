/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:34:37 by yurolive          #+#    #+#             */
/*   Updated: 2025/12/02 14:34:48 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other)
{
    Animal::operator=(other);
    std::cout << "Cat copy assignment called\n";
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!\n";
}