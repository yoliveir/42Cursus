/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:26:56 by yurolive          #+#    #+#             */
/*   Updated: 2026/02/06 18:27:01 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
    : AForm("Presidential", 25, 5), _target(target) {}

void PresidentialPardonForm::executeAction() const
{
    std::cout << _target
              << " has been pardoned by Zaphod Beeblebrox 🏛️\n";
}
