#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <vector>
#include <string>
#include "Contact.h"

class ContactManager {
public:
    void addContact(const std::string& name, const std::string& phone, const std::string& email);
    void displayContacts() const;
    bool editContact(const std::string& oldName, const std::string& newName, const std::string& newPhone, const std::string& newEmail);
    bool removeContact(const std::string& name);
    const Contact* searchByName(const std::string& name) const;
    const Contact* searchByPhone(const std::string& phone) const;
    const Contact* searchByEmail(const std::string& email) const;

private:
    std::vector<Contact> contacts;
};

#endif // CONTACTMANAGER_H