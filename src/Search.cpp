#include "Search.h"
#include "ContactManager.h"

const Contact* Search::searchByName(const std::vector<Contact>& contacts, const std::string& name) const {
    for (const auto& contact : contacts) {
        if (contact.getName() == name) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}

const Contact* Search::searchByPhone(const std::vector<Contact>& contacts, const std::string& phone) const {
    for (const auto& contact : contacts) {
        if (contact.getPhone() == phone) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}

const Contact* Search::searchByEmail(const std::vector<Contact>& contacts, const std::string& email) const {
    for (const auto& contact : contacts) {
        if (contact.getEmail() == email) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}