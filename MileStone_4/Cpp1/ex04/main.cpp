/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:13:25 by yurolive          #+#    #+#             */
/*   Updated: 2025/08/27 18:23:04 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 (string to replace) cannot be empty." << std::endl;
        return 1;
    }

    Replacer replacer(filename, s1, s2);
    if (!replacer.process()) {
        std::cerr << "Error: Could not process file." << std::endl;
        return 1;
    }

    std::cout << "File processed successfully." << std::endl;
    return 0;
}