#include "Contact.h"
#include <iostream>
#include <vector>
#include <string>

class ContactManager {
public:
    void addContact(const std::string& name, const std::string& phone, const std::string& email) {
        contacts.emplace_back(name, phone, email);
    }

    void displayContacts() const {
        for (const auto& contact : contacts) {
            contact.display();
            std::cout << "-------------------" << std::endl;
        }
    }

private:
    std::vector<Contact> contacts;
};