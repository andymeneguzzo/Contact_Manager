#include "ContactManager.h"
#include <iostream>
#include <algorithm>

void ContactManager::addContact(const std::string& name, const std::string& phone, const std::string& email) {
    contacts.emplace_back(name, phone, email);
}

void ContactManager::displayContacts() const {
    if (contacts.empty()) {
        std::cout << "No contacts to display." << std::endl;
        return;
    }

    for (const auto& contact : contacts) {
        contact.to_string();
        std::cout << "-------------------" << std::endl;
    }
}

bool ContactManager::editContact(const std::string& oldName, const std::string& newName, const std::string& newPhone, const std::string& newEmail) {
    auto it = std::find_if(contacts.begin(), contacts.end(), [&oldName](const Contact& contact) {
        return contact.getName() == oldName;
    });

    if (it != contacts.end()) {
        it->setName(newName);
        it->setPhone(newPhone);
        it->setEmail(newEmail);
        return true;
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

const Contact* ContactManager::searchByName(const std::string& name) const {
    auto it = std::find_if(contacts.begin(), contacts.end(), [&name](const Contact& contact) {
        return contact.getName() == name;
    });

    if (it != contacts.end()) {
        return &(*it);
    }
    return nullptr;
}

const Contact* ContactManager::searchByPhone(const std::string& phone) const {
    auto it = std::find_if(contacts.begin(), contacts.end(), [&phone](const Contact& contact) {
        return contact.getPhone() == phone;
    });

    if (it != contacts.end()) {
        return &(*it);
    }
    return nullptr;
}

const Contact* ContactManager::searchByEmail(const std::string& email) const {
    auto it = std::find_if(contacts.begin(), contacts.end(), [&email](const Contact& contact) {
        return contact.getEmail() == email;
    });

    if (it != contacts.end()) {
        return &(*it);
    }
    return nullptr;
}