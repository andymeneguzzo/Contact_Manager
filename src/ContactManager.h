#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <vector>
#include <string>
#include "Contact.h"
#include "Database.h"
#include "Sort.h"
#include "Filter.h"
#include "Statistics.h"
#include "Search.h"
#include "FileManager.h"

class ContactManager {
public:
    Sort sorter;
    Filter filter;
    Statistics stats;
    Search searcher;
    FileManager fileManager;
    std::vector<Contact> contacts;

    ContactManager();
    ~ContactManager();

    void addContact(const std::string& name, const std::string& phone, const std::string& email,
                    const std::string& dob, const std::string& gender, const std::string& status, 
                    const std::string& notes, const std::string& profession = "", 
                    const std::string& company = "", const std::string& jobPosition = "",
                    const std::string& companyAddress = "", const std::string& officePhone = "", const std::string& category, const std::string& group);
    void displayContacts() const;
    bool editContact(const std::string& oldName, const std::string& newName, const std::string& newPhone, const std::string& newEmail, const std::string& newDob, const std::string& newGender, const std::string& newStatus, const std::string& newNotes, const std::string& newProfession, const std::string& newCompany, const std::string& newJobPosition, const std::string& newCompanyAddress, const std::string& newOfficePhone, const std::string& newCategory, const std::string& newGroup);

    bool removeContact(const std::string& name);
    
    std::vector<Contact> findDuplicates(const std::string& name, const std::string& phone, const std::string& email) const;
    void generateStatistics() const;

    void loadContacts(const std::string& filename);
private:
    std::string dataFile = "contacts.txt";
};

#endif // CONTACTMANAGER_H