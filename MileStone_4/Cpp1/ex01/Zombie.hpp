/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:09:19 by yurolive          #+#    #+#             */
/*   Updated: 2025/08/06 18:42:55 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();  
		Zombie(std::string name);
		~Zombie();
		void announce( void );
		Zombie* newZombie(std::string name);
		void setName(const std::string& n);
};

Zombie* zombieHorde( int N, std::string name );

#endif // ZOMBIE_HPP
