#include "Database.h"
#include <iostream>
#include <stdexcept>

Database::Database(const std::string& dbName) : dbName(dbName), db(nullptr) {}

Database::~Database() {
    disconnect();
}

bool Database::connect() {
    if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Could not open database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    createTable();
    return true;
}

void Database::disconnect() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

void Database::createTable() {
    const char* sql = "CREATE TABLE IF NOT EXISTS contacts ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "name TEXT NOT NULL,"
                      "phone TEXT NOT NULL,"
                      "email TEXT NOT NULL,"
                      "dob TEXT,"
                      "gender TEXT,"
                      "status TEXT,"
                      "notes TEXT,"
                      "profession TEXT,"
                      "company TEXT,"
                      "jobPosition TEXT,"
                      "companyAddress TEXT,"
                      "officePhone TEXT,"
                      "category TEXT,"
                      "group TEXT);";

    char* errMsg;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

bool Database::addContact(const std::string& name, const std::string& phone, const std::string& email,
                          const std::string& dob, const std::string& gender, const std::string& status,
                          const std::string& notes, const std::string& profession, const std::string& company,
                          const std::string& jobPosition, const std::string& companyAddress,
                          const std::string& officePhone, const std::string& category, const std::string& group) {
    const char* sql = "INSERT INTO contacts (name, phone, email, dob, gender, status, notes, "
                      "profession, company, jobPosition, companyAddress, officePhone) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, phone.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, dob.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, gender.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, status.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, notes.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 8, profession.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 9, company.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 10, jobPosition.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 11, companyAddress.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 12, officePhone.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Failed to execute statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool Database::updateContact(const std::string& oldName, const std::string& newName, const std::string& newPhone, const std::string& newEmail,
                             const std::string& newDob, const std::string& newGender, const std::string& newStatus, const std::string& newNotes,
                             const std::string& newProfession, const std::string& newCompany, const std::string& newJobPosition,
                             const std::string& newCompanyAddress, const std::string& newOfficePhone, const std::string& newCategory, const std::string& newGroup) {
    const char* sql = "UPDATE contacts SET name = ?, phone = ?, email = ?, dob = ?, gender = ?, status = ?, notes = ?, "
                      "profession = ?, company = ?, jobPosition = ?, companyAddress = ?, officePhone = ?, category = ?, group = ? WHERE name = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, newName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, newPhone.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, newEmail.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, newDob.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, newGender.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, newStatus.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, newNotes.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 8, newProfession.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 9, newCompany.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 10, newJobPosition.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 11, newCompanyAddress.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 12, newOfficePhone.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 13, newCategory.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 14, newGroup.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 15, oldName.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Failed to execute statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool Database::removeContact(const std::string& name) {
    const char* sql = "DELETE FROM contacts WHERE name = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Failed to execute statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

std::vector<Contact> Database::getAllContacts() {
    std::vector<Contact> contacts;
    const char* sql = "SELECT name, phone, email, dob, gender, status, notes, "
                     "profession, company, jobPosition, companyAddress, officePhone FROM contacts;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return contacts;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string phone = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string dob = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string gender = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        std::string status = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        std::string notes = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
        std::string profession = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
        std::string company = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
        std::string jobPosition = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9));
        std::string companyAddress = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 10));
        std::string officePhone = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 11));
        contacts.emplace_back(name, phone, email, dob, gender, status, notes,
                              profession, company, jobPosition, companyAddress, officePhone);
    }

    sqlite3_finalize(stmt);
    return contacts;
}