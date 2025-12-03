/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:01:47 by yurolive          #+#    #+#             */
/*   Updated: 2025/11/27 18:02:25 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "\n=== CREACION ===\n";
    ScavTrap s("Guardian");
    FragTrap f("Fraggy");
    ClapTrap c("Basic");

    std::cout << "\n=== ATAQUES ===\n";
    s.attack("Invader");
    f.attack("Enemy");
    c.attack("Training Dummy");

    std::cout << "\n=== HABILIDADES ESPECIALES ===\n";
    s.guardGate();
    f.highFivesGuys();

    std::cout << "\n=== COPIAS ===\n";
    FragTrap copy(f);
    FragTrap assigned("TempFrag");
    assigned = f;

    std::cout << "\n=== DESTRUICION ===\n";
    return 0;
}