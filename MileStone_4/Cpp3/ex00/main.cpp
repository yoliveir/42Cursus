/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:13:32 by yurolive          #+#    #+#             */
/*   Updated: 2025/11/17 20:16:03 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("R2D2");
    ClapTrap b("Empire Bot");

    std::cout << "\n--- TEST 1: Ataques ---\n";
    a.attack("Empire Bot");
    b.takeDamage(0);

    std::cout << "\n--- TEST 2: Daño ---\n";
    b.takeDamage(5);
    b.takeDamage(10);

    std::cout << "\n--- TEST 3: Reparación ---\n";
    a.takeDamage(4);
    a.beRepaired(3);

    std::cout << "\n--- TEST 4: Energía hasta acabar ---\n";
    for (int i = 0; i < 12; i++)
        a.attack("Dummy");

    std::cout << "\n--- TEST 5: Constructor de copia ---\n";
    ClapTrap copy(a);

    std::cout << "\n--- TEST 6: Operador de asignación ---\n";
    ClapTrap assigned("Temp");
    assigned = b;

    std::cout << "\n--- END ---\n";
    return 0;
}