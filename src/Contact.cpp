#include <string>
#include <iostream>

class Contact {
public:
    Contact(const std::string& name, const std::string& phone, const std::string& email)
        : name(name), phone(phone), email(email) {}

    void display() const {
        std::cout << "Name: " << name << "\nPhone: " << phone << "\nEmail: " << email << std::endl;
    }

private:
    std::string name;
    std::string phone;
    std::string email;
};