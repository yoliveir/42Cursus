/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:28:13 by yurolive          #+#    #+#             */
/*   Updated: 2025/07/16 16:40:03 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //Equivalent of Printf
#include <iomanip> //input/output Manipulators
#include <sstream> //Convert strings to int (Atoi)
#include <cstdlib>
#include "PhoneBook.hpp"

std::string PhoneBook::formatField(const std::string &field) const
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    else
        return std::string(10 - field.length(), ' ') + field;
}

PhoneBook::PhoneBook() : contactCount(0), nextIndex(0) {}

void PhoneBook::addContact()
{
    std::string tmp;
    std::string fName, lName, nick, phone, secret;

    std::cout << "First Name: ";
    std::getline(std::cin, fName);
    std::cout << "Last Name: ";
    std::getline(std::cin, lName);
    std::cout << "Nickname: ";
    std::getline(std::cin, nick);
    std::cout << "Phone Number: ";
    std::getline(std::cin, phone);
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, secret);

    if (fName.empty() || lName.empty() || nick.empty() || phone.empty() || secret.empty())
    {
        std::cout << "All fields are required! Contact not saved." << std::endl;
        std::cout << "\nPress ENTER to continue ..." << std::endl;
        std::getline(std::cin, tmp);
        system("clear");
        return;
    }

    contacts[nextIndex].setContact(fName, lName, nick, phone, secret);
    nextIndex = (nextIndex + 1) % 8;
    if (contactCount < 8)
        contactCount++;
    std::cout << "Contact added!" << std::endl;
    std::cout << "\nPress ENTER to continue ..." << std::endl;
    std::getline(std::cin, tmp);
    system("clear");
}

void PhoneBook::searchContacts() const
{
    std::string tmp;
    std::string input;

    if (contactCount == 0) {
        std::cout << "No contacts available." << std::endl;
        std::cout << "\nPress ENTER to continue ..." << std::endl;
        std::getline(std::cin, tmp);
        system("clear");
        return;
    }

    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < contactCount; ++i) {
        std::cout << "|" << std::setw(10) << i
                    << "|" << formatField(contacts[i].getField(0))
                    << "|" << formatField(contacts[i].getField(1))
                    << "|" << formatField(contacts[i].getField(2)) << "|" << std::endl;
    }

    std::cout << "Enter contact index: ";
    std::getline(std::cin, input);
    int idx;
    std::stringstream ss(input);
    if (!(ss >> idx) || !(ss.eof()))
    {
        std::cout << "Invalid index!" << std::endl;
        std::cout << "\nPress ENTER to continue ..." << std::endl;
        std::getline(std::cin, tmp);
        system("clear");
        return;
    }

    if (idx < 0 || idx >= contactCount) {
        std::cout << "Invalid index!" << std::endl;
        std::cout << "\nPress ENTER to continue ..." << std::endl;
        std::getline(std::cin, tmp);
        system("clear");
    } else {
        contacts[idx].displayFull();
        std::cout << "\nPress ENTER to continue ..." << std::endl;
        std::getline(std::cin, tmp);
        system("clear");
    }
}