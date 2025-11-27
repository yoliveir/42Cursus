/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:38:51 by yurolive          #+#    #+#             */
/*   Updated: 2025/11/27 17:39:00 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap parameter constructor called for " << _name << "\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name), _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap copy assignment operator called\n";
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << _name << "\n";
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " cannot attack.\n";
        return;
    }

    _energyPoints--;
    std::cout << "ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is already destroyed!\n";
        return;
    }

    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name
              << " takes " << amount << " damage! Remaining HP: " << _hitPoints << "\n";

    if (_hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " has been destroyed!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ClapTrap " << _name
                  << " cannot repair itself.\n";
        return;
    }

    _energyPoints--;
    _hitPoints += amount;

    std::cout << "ClapTrap " << _name
              << " repairs itself for " << amount
              << " HP. Now: " << _hitPoints << "\n";
}