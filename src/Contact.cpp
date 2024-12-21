#include "Contact.h"
#include <iostream>

Contact::Contact(const std::string& name, const std::string& phone, const std::string& email)
    : name(name), phone(phone), email(email) {}

void Contact::to_string() const {
    std::cout << "Name: " << name << "\nPhone: " << phone << "\nEmail: " << email << std::endl;
}