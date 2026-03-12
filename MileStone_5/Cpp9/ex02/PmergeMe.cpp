/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:21:00 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/12 16:21:02 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

void PmergeMe::mergeInsertVector(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return;

    std::vector<int> mainChain;
    std::vector<int> pending;

    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        int a = vec[i];
        int b = vec[i + 1];

        if (a > b)
            std::swap(a, b);

        pending.push_back(a);
        mainChain.push_back(b);
    }

    if (vec.size() % 2)
        pending.push_back(vec.back());

    mergeInsertVector(mainChain);

    for (size_t i = 0; i < pending.size(); i++)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);

        mainChain.insert(pos, pending[i]);
    }

    vec = mainChain;
}

void PmergeMe::mergeInsertDeque(std::deque<int>& deq)
{
    if (deq.size() <= 1)
        return;

    std::deque<int> mainChain;
    std::deque<int> pending;

    for (size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        int a = deq[i];
        int b = deq[i + 1];

        if (a > b)
            std::swap(a, b);

        pending.push_back(a);
        mainChain.push_back(b);
    }

    if (deq.size() % 2)
        pending.push_back(deq.back());

    mergeInsertDeque(mainChain);

    for (size_t i = 0; i < pending.size(); i++)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);

        mainChain.insert(pos, pending[i]);
    }

    deq = mainChain;
}

void PmergeMe::sortVector(std::vector<int>& vec)
{
    mergeInsertVector(vec);
}

void PmergeMe::sortDeque(std::deque<int>& deq)
{
    mergeInsertDeque(deq);
}