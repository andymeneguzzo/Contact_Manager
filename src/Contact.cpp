#include "Contact.h"
#include <iostream>

Contact::Contact(const std::string& name, const std::string& phone, const std::string& email)
    : name(name), phone(phone), email(email) {}

void Contact::to_string() const {
    std::cout << "Name: " << name << "\nPhone: " << phone << "\nEmail: " << email << std::endl;
}

std::string Contact::getName() const {
    return name;
}

void Contact::setName(const std::string& name) {
    this->name = name;
}

void Contact::setPhone(const std::string& phone) {
    this->phone = phone;
}

void Contact::setEmail(const std::string& email) {
    this->email = email;
}