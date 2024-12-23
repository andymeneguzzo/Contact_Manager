#include "ContactManager.h"
#include "Database.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>

ContactManager::ContactManager() {}

ContactManager::~ContactManager() {}

void ContactManager::addContact(const std::string& name, const std::string& phone, 
    const std::string& email, const std::string& dob, const std::string& gender, 
    const std::string& status, const std::string& notes, const std::string& profession,
    const std::string& company, const std::string& jobPosition,
    const std::string& companyAddress, const std::string& officePhone) {
    
    contacts.emplace_back(name, phone, email, dob, gender, status, notes,
                         profession, company, jobPosition, companyAddress, officePhone);
    saveContacts(dataFile);
    Database db("contacts.db");
    db.connect();
    db.addContact(name, phone, email, dob, gender, status, notes);
    db.disconnect();
}

void ContactManager::displayContacts() const {
    if (contacts.empty()) {
        std::cout << "No contacts to display." << std::endl;
        return;
    }

    for (const auto& contact : contacts) {
        contact.to_string();
        std::cout << "-------------------" << std::endl;
    }
}

bool ContactManager::editContact(const std::string& oldName, const std::string& newName, const std::string& newPhone, const std::string& newEmail, const std::string& newDob, const std::string& newGender, const std::string& newStatus, const std::string& newNotes) {
    auto it = std::find_if(contacts.begin(), contacts.end(), [&oldName](const Contact& contact) {
        return contact.getName() == oldName;
    });

    if (it != contacts.end()) {
        it->setName(newName);
        it->setPhone(newPhone);
        it->setEmail(newEmail);
        it->setDob(newDob);
        it->setGender(newGender);
        it->setStatus(newStatus);
        it->setNotes(newNotes);
        saveContacts(dataFile);
        Database db("contacts.db");
        db.connect();
        db.updateContact(oldName, newName, newPhone, newEmail, newDob, newGender, newStatus, newNotes, it->getProfession(), it->getCompany(), it->getJobPosition(), it->getCompanyAddress(), it->getOfficePhone());
        db.disconnect();
        return true;
    }
    return false;
}

bool ContactManager::removeContact(const std::string& name) {
    auto it = std::remove_if(contacts.begin(), contacts.end(), [&name](const Contact& contact) {
        return contact.getName() == name;
    });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        saveContacts(dataFile);
        Database db("contacts.db");
        db.connect();
        db.removeContact(name);
        db.disconnect();
        return true;
    }
    return false;
}

void ContactManager::loadContacts(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return;
    }

    std::string name, phone, email, dob, gender, status, notes;
    while (file >> name >> phone >> email >> dob >> gender >> status >> notes) {
        contacts.emplace_back(name, phone, email, dob, gender, status, notes);
    }

    file.close();
}

void ContactManager::saveContacts(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return;
    }
    
    for (const auto& contact : contacts) {
        file << contact.getName() << " "
             << contact.getPhone() << " "
             << contact.getEmail() << " "
             << contact.getDob() << " "
             << contact.getGender() << " "
             << contact.getStatus() << " "
             << contact.getNotes() << " "
             << contact.getProfession() << " "
             << contact.getCompany() << " "
             << contact.getJobPosition() << " "
             << contact.getCompanyAddress() << " "
             << contact.getOfficePhone() << std::endl;
    }

    file.close();
}

void ContactManager::exportToCSV(const std::string& filename) const {
    std::ofstream file(filename);

    if(!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return;
    }

    // Write in CSV header
    file << "Name,Phone,Email,Dob,Gender,Status,Notes,Profession,Company,JobPosition,CompanyAddress,OfficePhone\n";

    // Write contact data
    for (const auto& contact : contacts) {
        file << contact.getName() << ","
             << contact.getPhone() << ","
             << contact.getEmail() << ","
             << contact.getDob() << ","
             << contact.getGender() << ","
             << contact.getStatus() << ","
             << contact.getNotes() << ","
             << contact.getProfession() << ","
             << contact.getCompany() << ","
             << contact.getJobPosition() << ","
             << contact.getCompanyAddress() << ","
             << contact.getOfficePhone() << "\n";
    }

    file.close();
    std::cout << "Contacts exported successfully to " << filename << std::endl;
}

std::vector<Contact> ContactManager::findDuplicates(const std::string& name, const std::string& phone, const std::string& email) const {
    std::vector<Contact> duplicates;

    for(const auto& contact : contacts) {
        if (contact.getName() == name || contact.getPhone() == phone || contact.getEmail() == email) {
            duplicates.push_back(contact);
        }
    }
    return duplicates;
}

void ContactManager::generateStatistics() const {
    std::map<std::string, int> genderStats;
    std::map<std::string, int> statusStats;
    std::map<std::string, int> professionStats;

    for (const auto& contact : contacts) {
        genderStats[contact.getGender()]++;
        statusStats[contact.getStatus()]++;
        professionStats[contact.getProfession()]++;
    }

    std::cout << "\n=== Statistiche ===\n";

    std::cout << "\nGenere:\n";
    for (const auto& [gender, count] : genderStats) {
        std::cout << gender << ": " << count << "\n";
    }

    std::cout << "\nStato Civile:\n";
    for (const auto& [status, count] : statusStats) {
        std::cout << status << ": " << count << "\n";
    }

    std::cout << "\nProfessione:\n";
    for (const auto& [profession, count] : professionStats) {
        std::cout << profession << ": " << count << "\n";
    }
}