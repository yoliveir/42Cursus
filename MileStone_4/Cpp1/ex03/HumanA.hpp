/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:56:32 by yurolive          #+#    #+#             */
/*   Updated: 2025/08/11 20:00:28 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
	    std::string name;
	    Weapon& weapon;

	public:
	    HumanA(const std::string& name, Weapon& weapon);
	    void attack() const;
};

#endif //HUMANA_HPP