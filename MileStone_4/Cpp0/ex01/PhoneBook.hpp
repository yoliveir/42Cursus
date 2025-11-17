/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:24:41 by yurolive          #+#    #+#             */
/*   Updated: 2025/07/16 16:39:43 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int contactCount;
        int nextIndex;

        std::string formatField(const std::string &) const;

    public:
        PhoneBook();
        void addContact();
        void searchContacts() const;
};

#endif // PHONEBOOK_HPP