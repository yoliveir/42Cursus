/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:47:35 by yurolive          #+#    #+#             */
/*   Updated: 2025/08/11 19:48:57 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private:
	    std::string type;

	public:
	    Weapon(const std::string& type);
	    const std::string& getType() const;
	    void setType(const std::string& newType);
};

#endif //WEAPON_HPP