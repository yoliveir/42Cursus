/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:46:05 by yurolive          #+#    #+#             */
/*   Updated: 2025/11/27 17:46:28 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "\n=== CREACION ===\n";
    ScavTrap s("Guardian");
    ClapTrap c("Basic");

    std::cout << "\n=== ATAQUES ===\n";
    s.attack("Invader");
    c.attack("Training Dummy");

    std::cout << "\n=== HABILIDAD ESPECIAL ===\n";
    s.guardGate();

    std::cout << "\n=== COPIAS ===\n";
    ScavTrap copy(s);
    ScavTrap assigned("Temp");
    assigned = s;

    std::cout << "\n=== DESTRUICION ===\n";
    return 0;
}
