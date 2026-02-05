/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:29:30 by yurolive          #+#    #+#             */
/*   Updated: 2026/02/05 16:29:38 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "\n--- Creating bureaucrats ---\n";
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    std::cout << boss << "\n";
    std::cout << intern << "\n";

    std::cout << "\n--- Creating forms ---\n";
    Form tax("Tax Form", 50, 20);
    Form secret("Secret Form", 1, 1);

    std::cout << tax << "\n";
    std::cout << secret << "\n";

    std::cout << "\n--- Signing attempts ---\n";
    intern.signForm(tax);     // should fail
    boss.signForm(tax);       // should succeed
    intern.signForm(secret);  // fail hard
    boss.signForm(secret);    // succeed

    std::cout << "\n--- Final form states ---\n";
    std::cout << tax << "\n";
    std::cout << secret << "\n";

    return 0;
}