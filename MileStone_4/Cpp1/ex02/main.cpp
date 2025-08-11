/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:10:07 by yurolive          #+#    #+#             */
/*   Updated: 2025/08/11 18:35:56 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;

    std::string& stringREF = str;

    std::cout << "Dirección de str:	" << &str << std::endl;
    std::cout << "Dirección en stringPTR:	" << stringPTR << std::endl;
    std::cout << "Dirección en stringREF:	" << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "Valor de str:		" << str << std::endl;
    std::cout << "Valor apuntado por PTR:	" << *stringPTR << std::endl;
    std::cout << "Valor de stringREF:    	" << stringREF << std::endl;

    return 0;
}