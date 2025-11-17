/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:09:15 by yurolive          #+#    #+#             */
/*   Updated: 2025/08/27 18:22:04 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>

class Replacer {
private:
    std::string filename;
    std::string s1;
    std::string s2;

public:
    Replacer(const std::string& filename, const std::string& s1, const std::string& s2);
    bool process();
};

#endif //REPLACER_HPP