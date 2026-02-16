/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:22:01 by yurolive          #+#    #+#             */
/*   Updated: 2026/02/16 18:23:55 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern intern;
    Bureaucrat boss("Boss", 1);

    AForm* f1 = intern.makeForm("robotomy request", "Bender");
    AForm* f2 = intern.makeForm("shrubbery creation", "Home");
    AForm* f3 = intern.makeForm("presidential pardon", "Arthur Dent");
    AForm* f4 = intern.makeForm("invalid form", "Nobody");

    std::cout << "\n--- Signing and executing ---\n";

    if (f1) {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }

    if (f2) {
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }

    if (f3) {
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
    }

    return 0;
}