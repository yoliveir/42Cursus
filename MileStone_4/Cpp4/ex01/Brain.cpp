/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:02:40 by yurolive          #+#    #+#             */
/*   Updated: 2025/12/02 15:03:17 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "[Brain] Constructor called\n";
}

Brain::Brain(const Brain& other)
{
    std::cout << "[Brain] Copy constructor called\n";
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "[Brain] Copy assignment called\n";
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "[Brain] Destructor called\n";
}

const std::string& Brain::getIdea(int index) const {
    return ideas[index];
}

void Brain::setIdea(int index, const std::string& idea) {
    ideas[index] = idea;
}