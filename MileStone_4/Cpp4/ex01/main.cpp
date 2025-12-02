/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:13:13 by yurolive          #+#    #+#             */
/*   Updated: 2025/12/02 15:43:29 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int N = 10;
    Animal* animals[N];

    for (int i = 0; i < N / 2; i++)
        animals[i] = new Dog();
    for (int i = N / 2; i < N; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Making sounds ---\n";
    for (int i = 0; i < N; i++)
        animals[i]->makeSound();

    std::cout << "\n--- Deleting animals ---\n";
    for (int i = 0; i < N; i++)
        delete animals[i];

    std::cout << "\n--- Testing deep copy ---\n";
    Dog original;
    original.makeSound();

    Dog copy = original;
    copy.makeSound();

	std::cout << "Brain do original: " << original.getBrain() << "\n";
    std::cout << "Brain da cópia:    " << copy.getBrain() << "\n";
    
    return 0;
}