#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <vector>
#include <string>
#include "Contact.h"
#include "Database.h"
#include "Sort.h"
#include "Filter.h"
#include "Statistics.h"

class ContactManager {
public:
    Sort sorter;
    Filter filter;
    Statistics stats;
    std::vector<Contact> contacts;

    ContactManager();
    ~ContactManager();

    void addContact(const std::string& name, const std::string& phone, const std::string& email,
                    const std::string& dob, const std::string& gender, const std::string& status, 
                    const std::string& notes, const std::string& profession = "", 
                    const std::string& company = "", const std::string& jobPosition = "",
                    const std::string& companyAddress = "", const std::string& officePhone = "");
    void displayContacts() const;
    bool editContact(const std::string& oldName, const std::string& newName, const std::string& newPhone, const std::string& newEmail,
                     const std::string& newDob, const std::string& newGender, const std::string& newStatus, const std::string& newNotes);
    bool removeContact(const std::string& name);
    const Contact* searchByName(const std::string& name) const;
    const Contact* searchByPhone(const std::string& phone) const;
    const Contact* searchByEmail(const std::string& email) const;
    void loadContacts(const std::string& filename);
    void saveContacts(const std::string& filename) const;

    // Additional method to find duplicates
    std::vector<Contact> findDuplicates(const std::string& name, const std::string& phone, const std::string& email) const;

    // Statistics
    void generateStatistics() const;

private:
    std::string dataFile = "contacts.txt";
};

#endif // CONTACTMANAGER_H