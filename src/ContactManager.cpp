#include "ContactManager.h"
#include "Database.h"
#include "FileManager.h"
#include "Search.h"
#include <iostream>
#include <algorithm>

ContactManager::ContactManager() {}

ContactManager::~ContactManager() {}

void ContactManager::addContact(const std::string& name, const std::string& phone, 
    const std::string& email, const std::string& dob, const std::string& gender, 
    const std::string& status, const std::string& notes, const std::string& profession,
    const std::string& company, const std::string& jobPosition,
    const std::string& companyAddress, const std::string& officePhone,
    const std::string& category, const std::string& group) {
    
    contacts.emplace_back(name, phone, email, dob, gender, status, notes,
                         profession, company, jobPosition, companyAddress, officePhone, category, group);
    FileManager fileManager;
    fileManager.saveContacts(dataFile, contacts);
    Database db("contacts.db");
    db.connect();
    db.addContact(name, phone, email, dob, gender, status, notes, profession, company, jobPosition, companyAddress, officePhone, category, group);
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

bool ContactManager::editContact(const std::string& oldName, const std::string& newName, const std::string& newPhone, const std::string& newEmail, const std::string& newDob, const std::string& newGender, const std::string& newStatus, const std::string& newNotes, const std::string& newProfession, const std::string& newCompany, const std::string& newJobPosition, const std::string& newCompanyAddress, const std::string& newOfficePhone, const std::string& newCategory, const std::string& newGroup) {
    auto it = std::find_if(contacts.begin(), contacts.end(), [&oldName](const Contact& contact) {
        return contact.getName() == oldName;
    });

    if (it != contacts.end()) {
        if (!newName.empty()) it->setName(newName);
        if (!newPhone.empty()) it->setPhone(newPhone);
        if (!newEmail.empty()) it->setEmail(newEmail);
        if (!newDob.empty()) it->setDob(newDob);
        if (!newGender.empty()) it->setGender(newGender);
        if (!newStatus.empty()) it->setStatus(newStatus);
        if (!newNotes.empty()) it->setNotes(newNotes);
        if (!newProfession.empty()) it->setProfession(newProfession);
        if (!newCompany.empty()) it->setCompany(newCompany);
        if (!newJobPosition.empty()) it->setJobPosition(newJobPosition);
        if (!newCompanyAddress.empty()) it->setCompanyAddress(newCompanyAddress);
        if (!newOfficePhone.empty()) it->setOfficePhone(newOfficePhone);
        if (!newCategory.empty()) it->setCategory(newCategory);
        if (!newGroup.empty()) it->setGroup(newGroup);

        FileManager fileManager;
        fileManager.saveContacts(dataFile, contacts);
        Database db("contacts.db");
        db.connect();
        db.updateContact(oldName, it->getName(), it->getPhone(), it->getEmail(), it->getDob(), it->getGender(), it->getStatus(), it->getNotes(), it->getProfession(), it->getCompany(), it->getJobPosition(), it->getCompanyAddress(), it->getOfficePhone(), it->getCategory(), it->getGroup());
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
        FileManager fileManager;
        fileManager.saveContacts(dataFile, contacts);
        Database db("contacts.db");
        db.connect();
        db.removeContact(name);
        db.disconnect();
        return true;
    }
    return false;
}

void ContactManager::loadContacts(const std::string& filename) {
    FileManager fileManager;
    contacts.clear();
    std::vector<Contact> loadedContacts = fileManager.loadContacts(filename);
    contacts.insert(contacts.end(), loadedContacts.begin(), loadedContacts.end());
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
    Statistics stats;
    stats.generateStatistics(contacts);
}