#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <vector>
#include <string>
#include "Contact.h"
#include "Database.h"

class ContactManager {
public:
    ContactManager();
    ~ContactManager();

    void addContact(const std::string& name, const std::string& phone, const std::string& email);
    void displayContacts() const;
    bool editContact(const std::string& oldName, const std::string& newName, const std::string& newPhone, const std::string& newEmail);
    bool removeContact(const std::string& name);
    const Contact* searchByName(const std::string& name) const;
    const Contact* searchByPhone(const std::string& phone) const;
    const Contact* searchByEmail(const std::string& email) const;
    void loadContacts(const std::string& filename);
    void saveContacts(const std::string& filename) const;

private:
    std::vector<Contact> contacts;
    std::string dataFile = "contacts.txt";
};

#endif // CONTACTMANAGER_H