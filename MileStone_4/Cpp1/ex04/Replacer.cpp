/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:08:28 by yurolive          #+#    #+#             */
/*   Updated: 2025/08/27 18:08:32 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"
#include <fstream>
#include <iostream>

Replacer::Replacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {}

bool Replacer::process() {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Cannot open input file." << std::endl;
        return false;
    }

    std::ofstream outfile(filename + ".replace");
    if (!outfile) {
        std::cerr << "Error: Cannot create output file." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::string newLine;
        size_t i = 0;

        while (i < line.length()) {
            if (line.substr(i, s1.length()) == s1) {
                newLine += s2;
                i += s1.length();
            } else {
                newLine += line[i];
                ++i;
            }
        }

        outfile << newLine << std::endl;
    }

    return true;
}