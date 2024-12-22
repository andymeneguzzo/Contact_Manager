#include "ContactManager.h"
#include "Database.h"
#include <iostream>
#include <algorithm>
#include <fstream>

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
        db.updateContact(oldName, newName, newPhone, newEmail, newDob, newGender, newStatus, newNotes);
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
        file << contact.getName() << " " << contact.getPhone() << " " << contact.getEmail() << " " << contact.getDob() << " " << contact.getGender() << " " << contact.getStatus() << " " << contact.getNotes() << std::endl;
    }

    file.close();
}

// Sorting methods
void ContactManager::sortByName() {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getName() < b.getName();
    });
}

void ContactManager::sortByPhone() {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getPhone() < b.getPhone();
    });
}

void ContactManager::sortByEmail() {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getEmail() < b.getEmail();
    });
}

void ContactManager::sortByDob() {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getDob() < b.getDob();
    });
}

void ContactManager::sortByGender() {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getGender() < b.getGender();
    });
}

void ContactManager::sortByStatus() {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getStatus() < b.getStatus();
    });
}

// Filtering methods
std::vector<Contact> ContactManager::filterByName(const std::string& name) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&name](const Contact& contact) {
        return contact.getName() == name;
    });
    return result;
}

std::vector<Contact> ContactManager::filterByPhone(const std::string& phone) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&phone](const Contact& contact) {
        return contact.getPhone() == phone;
    });
    return result;
}

std::vector<Contact> ContactManager::filterByEmail(const std::string& email) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&email](const Contact& contact) {
        return contact.getEmail() == email;
    });
    return result;
}

std::vector<Contact> ContactManager::filterByDob(const std::string& dob) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&dob](const Contact& contact) {
        return contact.getDob() == dob;
    });
    return result;
}

std::vector<Contact> ContactManager::filterByGender(const std::string& gender) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&gender](const Contact& contact) {
        return contact.getGender() == gender;
    });
    return result;
}

std::vector<Contact> ContactManager::filterByStatus(const std::string& status) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&status](const Contact& contact) {
        return contact.getStatus() == status;
    });
    return result;
}