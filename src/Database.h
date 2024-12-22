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
    bool addContact(const std::string& name, const std::string& phone, const std::string& email);
    bool updateContact(const std::string& oldName, const std::string& newName, const std::string& newPhone, const std::string& newEmail);
    bool removeContact(const std::string& name);
    std::vector<Contact> getAllContacts();

private:
    sqlite3* db;
    std::string dbName;

    bool executeSQL(const std::string& sql);
    void createTable();
};

#endif // DATABASE_H