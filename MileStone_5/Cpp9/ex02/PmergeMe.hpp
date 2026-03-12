/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:20:38 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/12 16:20:40 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe
{
public:
    PmergeMe();

    void sortVector(std::vector<int>& vec);
    void sortDeque(std::deque<int>& deq);

private:

    void mergeInsertVector(std::vector<int>& vec);
    void mergeInsertDeque(std::deque<int>& deq);
};

#endif