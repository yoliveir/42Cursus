/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:54:01 by yurolive          #+#    #+#             */
/*   Updated: 2025/07/16 15:54:25 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //Equivalent of Printf
#include <iomanip> //Input/Output Manipulators
#include "Contact.hpp"

void Contact::setContact(const std::string &fName, const std::string &lName, const std::string &phone
                        , const std::string &darkSec, const std::string &nName)
{
    firstName = fName;
    lastName = lName;
    phoneNumber = phone;
    darkSecret = darkSec;
    nickname = nName;
}

std::string Contact::getField(int index) const
{
    switch (index)
	{
        case 0: return firstName;
        case 1: return lastName;
        case 2: return phoneNumber;
        case 3: return darkSecret;
        case 4: return nickname;
        default: return "";
    }
}

void Contact::displayFull() const
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Darkest Secret: " << darkSecret << std::endl;
}

bool Contact::isEmpty() const
{
    return firstName.empty();
}