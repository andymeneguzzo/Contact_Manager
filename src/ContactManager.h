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

    // New methods for sorting and filtering
    void sortByName();
    void sortByPhone();
    void sortByEmail();
    void sortByDob();
    void sortByGender();
    void sortByStatus();
    std::vector<Contact> filterByName(const std::string& name) const;
    std::vector<Contact> filterByPhone(const std::string& phone) const;
    std::vector<Contact> filterByEmail(const std::string& email) const;
    std::vector<Contact> filterByDob(const std::string& dob) const;
    std::vector<Contact> filterByGender(const std::string& gender) const;
    std::vector<Contact> filterByStatus(const std::string& status) const;

    // Additional sorting methods
    void sortByProfession();
    void sortByCompany();
    void sortByJobPosition();

    // Additional filtering methods
    std::vector<Contact> filterByProfession(const std::string& profession) const;
    std::vector<Contact> filterByCompany(const std::string& company) const;
    std::vector<Contact> filterByJobPosition(const std::string& position) const;

private:
    std::vector<Contact> contacts;
    std::string dataFile = "contacts.txt";
};

#endif // CONTACTMANAGER_H