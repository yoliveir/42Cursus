/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:54:49 by yurolive          #+#    #+#             */
/*   Updated: 2025/06/18 16:32:15 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //Equivalent of Printf
#include <cctype> //std::toupper
#include <string> //std::string

int	main(int argc, char **argv)
{
	std::string str;
	std::size_t j;
	int	i;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;//endl = \n + Clean Output Buffer
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		str = argv[i];
		j = 0;
		while (j < str.length())
		{
			std::cout << static_cast<char>(std::toupper(str[j]));
			++j;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}