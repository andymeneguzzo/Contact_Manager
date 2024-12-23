#include "Contact.h"
#include <iostream>

Contact::Contact(const std::string& name, const std::string& phone, const std::string& email, 
                const std::string& dob, const std::string& gender, const std::string& status, 
                const std::string& notes, const std::string& profession, const std::string& company,
                const std::string& jobPosition, const std::string& companyAddress, 
                const std::string& officePhone, const std::string& category, const std::string& group) 
      : name(name), phone(phone), email(email), dob(dob), gender(gender), status(status), 
      notes(notes), profession(profession), company(company), jobPosition(jobPosition), companyAddress(companyAddress), officePhone(officePhone), category(category), group(group) {}

void Contact::to_string() const {
    std::cout << "Name: " << name 
              << "\nPhone: " << phone 
              << "\nEmail: " << email 
              << "\nDate of Birth: " << dob 
              << "\nGender: " << gender 
              << "\nStatus: " << status 
              << "\nNotes: " << notes
              << "\nProfession: " << profession
              << "\nCompany: " << company
              << "\nJob Position: " << jobPosition
              << "\nCompany Address: " << companyAddress
              << "\nOffice Phone: " << officePhone 
              << std::endl;
}

std::string Contact::getName() const {
    return name;
}

std::string Contact::getPhone() const {
    return phone;
}

std::string Contact::getEmail() const {
    return email;
}

std::string Contact::getDob() const {
    return dob;
}

std::string Contact::getGender() const {
    return gender;
}

std::string Contact::getStatus() const {
    return status;
}

std::string Contact::getNotes() const {
    return notes;
}

std::string Contact::getProfession() const { return profession; }
std::string Contact::getCompany() const { return company; }
std::string Contact::getJobPosition() const { return jobPosition; }
std::string Contact::getCompanyAddress() const { return companyAddress; }
std::string Contact::getOfficePhone() const { return officePhone; }

void Contact::setName(const std::string& name) {
    this->name = name;
}

void Contact::setPhone(const std::string& phone) {
    this->phone = phone;
}

void Contact::setEmail(const std::string& email) {
    this->email = email;
}

void Contact::setDob(const std::string& dob) {
    this->dob = dob;
}

void Contact::setGender(const std::string& gender) {
    this->gender = gender;
}

void Contact::setStatus(const std::string& status) {
    this->status = status;
}

void Contact::setNotes(const std::string& notes) {
    this->notes = notes;
}

void Contact::setProfession(const std::string& profession) { this->profession = profession; }
void Contact::setCompany(const std::string& company) { this->company = company; }
void Contact::setJobPosition(const std::string& jobPosition) { this->jobPosition = jobPosition; }
void Contact::setCompanyAddress(const std::string& companyAddress) { this->companyAddress = companyAddress; }
void Contact::setOfficePhone(const std::string& officePhone) { this->officePhone = officePhone; }