/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:59:07 by yurolive          #+#    #+#             */
/*   Updated: 2025/08/11 20:00:04 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
	    std::string name;
	    Weapon* weapon;

	public:
	    HumanB(const std::string& name);
	    void setWeapon(Weapon& weapon);
	    void attack() const;
};

#endif //HUMANB_HPP