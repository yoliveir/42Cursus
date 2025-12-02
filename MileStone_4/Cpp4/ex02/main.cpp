/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:41:23 by yurolive          #+#    #+#             */
/*   Updated: 2025/12/02 15:45:02 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int N = 10;
    AAnimal* animals[N];

    std::cout << "--- Creating Animals ---\n";
    for (int i = 0; i < N / 2; i++)
        animals[i] = new Dog();
    for (int i = N / 2; i < N; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Making sounds ---\n";
    for (int i = 0; i < N; i++)
        animals[i]->makeSound();

    std::cout << "\n--- Deleting Animals ---\n";
    for (int i = 0; i < N; i++)
        delete animals[i];

    std::cout << "\n--- Testing deep copy ---\n";
    Dog original;
    original.makeSound();

    Dog copy = original;
    copy.makeSound();

    std::cout << "\nOriginal Dog Brain address: " << &original << "\n";
    std::cout << "Copied Dog Brain address:   " << &copy << "\n";

	//AAnimal* z = new AAnimal();
	
    return 0;
}