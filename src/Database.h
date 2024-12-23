#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <sqlite3.h>
#include "Contact.h"

class Database {
public:
    Database(const std::string& dbName);
    ~Database();

    bool connect();
    void disconnect();
    bool addContact(const std::string& name, const std::string& phone, const std::string& email,
                    const std::string& dob, const std::string& gender, const std::string& status, 
                    const std::string& notes, const std::string& profession = "",
                    const std::string& company = "", const std::string& jobPosition = "",
                    const std::string& companyAddress = "", const std::string& officePhone = "");
    bool updateContact(const std::string& oldName, const std::string& newName, const std::string& newPhone, const std::string& newEmail,
                       const std::string& newDob, const std::string& newGender, const std::string& newStatus, const std::string& newNotes,
                       const std::string& newProfession, const std::string& newCompany,
                       const std::string& newJobPosition, const std::string& newCompanyAddress,
                       const std::string& newOfficePhone);
    bool removeContact(const std::string& name);
    std::vector<Contact> getAllContacts();

private:
    sqlite3* db;
    std::string dbName;

    void createTable();
};

#endif // DATABASE_H