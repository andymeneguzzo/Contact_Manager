#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <vector>
#include <string>
#include "Contact.h"

class ContactManager {
public:
    void addContact(const std::string& name, const std::string& phone, const std::string& email);
    void displayContacts() const;

private:
    std::vector<Contact> contacts;
};

#endif // CONTACTMANAGER_H