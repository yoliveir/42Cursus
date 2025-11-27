/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:59:32 by yurolive          #+#    #+#             */
/*   Updated: 2025/11/27 18:01:25 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Ultra Droid")
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "FragTrap parameter constructor called for " << _name << "\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "FragTrap copy assignment operator called\n";
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << _name << "\n";
}

void FragTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "FragTrap " << _name << " cannot attack.\n";
        return;
    }

    _energyPoints--;
    std::cout << "FragTrap " << _name << " attacks " << target
        << " fiercely for " << _attackDamage << " damage!\n";
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " requests a nice high five! ✋\n";
}