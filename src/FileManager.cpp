#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Contact.h"

void FileManager::saveContacts(const std::string& filename, const std::vector<Contact>& contacts) const {
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
             << contact.getOfficePhone() << " "
             << contact.getCategory() << " "
             << contact.getGroup() << std::endl;
    }

    file.close();
}

std::vector<Contact> FileManager::loadContacts(const std::string& filename) const {
    std::vector<Contact> contacts;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return contacts;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, phone, email, dob, gender, status, notes, profession, company, jobPosition, companyAddress, officePhone, category, group;

        ss >> name >> phone >> email >> dob >> gender >> status >> notes >> profession >> company >> jobPosition >> companyAddress >> officePhone >> category >> group;

        contacts.emplace_back(name, phone, email, dob, gender, status, notes, profession, company, jobPosition, companyAddress, officePhone, category, group);
    }

    file.close();
    return contacts;
}

void FileManager::exportToCSV(const std::string& filename, const std::vector<Contact>& contacts) const {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return;
    }

    // Write in CSV header
    file << "Name,Phone,Email,Dob,Gender,Status,Notes,Profession,Company,JobPosition,CompanyAddress,OfficePhone,Category,Group\n";

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
             << contact.getOfficePhone() << ","
             << contact.getCategory() << ","
             << contact.getGroup() << "\n";
    }

    file.close();
    std::cout << "Contacts exported successfully to " << filename << std::endl;   
}

std::vector<Contact> FileManager::importFromCSV(const std::string& filename) const {
    std::vector<Contact> contacts;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return contacts;
    }

    std::string line;
    std::getline(file, line); // Salta l'intestazione

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, phone, email, dob, gender, status, notes, profession, company, jobPosition, companyAddress, officePhone, category, group;

        std::getline(ss, name, ',');
        std::getline(ss, phone, ',');
        std::getline(ss, email, ',');
        std::getline(ss, dob, ',');
        std::getline(ss, gender, ',');
        std::getline(ss, status, ',');
        std::getline(ss, notes, ',');
        std::getline(ss, profession, ',');
        std::getline(ss, company, ',');
        std::getline(ss, jobPosition, ',');
        std::getline(ss, companyAddress, ',');
        std::getline(ss, officePhone, ',');
        std::getline(ss, category, ',');
        std::getline(ss, group, ',');

        contacts.emplace_back(name, phone, email, dob, gender, status, notes, profession, company, jobPosition, companyAddress, officePhone, category, group);
    }

    file.close();
    return contacts;
}