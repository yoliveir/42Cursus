#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cctype> //std::toupper

std::string toUpper(const std::string& str) {
    std::string result = str;
    for (size_t i = 0; i < result.length(); ++i) {
        if (result[i] >= 'a' && result[i] <= 'z') {
            result[i] = toupper(result[i]);
        }
    }
    return result;
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to the 80s Crappy Awesome PhoneBook!" << std::endl;
    while (true) {
        std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        command = toUpper(command); 

        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContacts();
        } else if (command == "EXIT") {
            std::cout << "Goodbye! Contacts erased forever..." << std::endl;
            break;
        } else {
            std::cout << "Unknown command!" << std::endl;
        }
    }

    return 0;
}