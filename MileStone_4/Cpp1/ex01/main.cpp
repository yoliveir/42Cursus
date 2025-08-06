/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:10:07 by yurolive          #+#    #+#             */
/*   Updated: 2025/08/06 18:41:57 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N;
    int i;

    N = 5;
    Zombie* horde = zombieHorde(N, "Zed");

    if (horde) {
        for (i = 0; i < N; ++i)
            horde[i].announce();
        delete[] horde;
    }

    return 0;
}