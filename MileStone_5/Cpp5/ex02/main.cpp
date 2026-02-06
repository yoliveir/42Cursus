/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:27:18 by yurolive          #+#    #+#             */
/*   Updated: 2026/02/06 18:27:23 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>

int main()
{
    srand(time(NULL));

    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 140);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    worker.signForm(shrub);
    boss.signForm(robo);
    boss.signForm(pardon);

    worker.executeForm(shrub);
    boss.executeForm(robo);
    boss.executeForm(pardon);

    return 0;
}