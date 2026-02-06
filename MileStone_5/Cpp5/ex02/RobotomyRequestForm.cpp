/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:24:21 by yurolive          #+#    #+#             */
/*   Updated: 2026/02/06 18:24:24 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
    : AForm("Robotomy", 72, 45), _target(target) {}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "🔩 Drilling noises...\n";
    if (rand() % 2)
        std::cout << _target << " robotomized successfully 🤖\n";
    else
        std::cout << "Robotomy failed ❌\n";
}
