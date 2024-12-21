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

bool ContactManager::editContact(const std::string& oldName, const std::string& newName, const std::string& newPhone, const std::string& newEmail) {
    for (auto& contact : contacts) {
        if (contact.getName() == oldName) {
            contact.setName(newName);
            contact.setPhone(newPhone);
            contact.setEmail(newEmail);
            return true;
        }
    }
    return false;
}

bool ContactManager::removeContact(const std::string& name) {
    auto it = std::remove_if(contacts.begin(), contacts.end(), [&name](const Contact& contact) {
        return contact.getName() == name;
    });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        return true;
    }
    return false;
}