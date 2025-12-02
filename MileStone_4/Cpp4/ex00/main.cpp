/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:39:22 by yurolive          #+#    #+#             */
/*   Updated: 2025/12/02 14:48:40 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n=== BASIC TESTS ===\n";
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << "\n";
    std::cout << i->getType() << "\n";

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== WRONG ANIMAL TESTS ===\n";
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    wrong->makeSound();
    wrongCat->makeSound();

    delete wrong;
    delete wrongCat;

    std::cout << "\n=== DIRECT WRONGCAT TEST ===\n";
    WrongCat wc;
    wc.makeSound();

    std::cout << "\n=== COPY & ASSIGNMENT TESTS ===\n";
    Dog d1;
    Dog d2(d1);
    Dog d3;
    d3 = d2;

    Cat c1;
    Cat c2(c1);
    Cat c3;
    c3 = c2;

    return 0;
}