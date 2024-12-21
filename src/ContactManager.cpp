#include "ContactManager.h"
#include <iostream>

void ContactManager::addContact(const std::string& name, const std::string& phone, const std::string& email) {
    contacts.emplace_back(name, phone, email);
}

void ContactManager::displayContacts() const {
    for (const auto& contact : contacts) {
        contact.to_string();
        std::cout << "-------------------" << std::endl;
    }
}