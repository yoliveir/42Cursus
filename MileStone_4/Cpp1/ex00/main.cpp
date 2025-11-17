/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:10:07 by yurolive          #+#    #+#             */
/*   Updated: 2025/08/06 18:21:13 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie* z1 = newZombie("Rodrigo");
    z1->announce();
    delete z1;

    randomChump("Rogerio");

    return 0;
}