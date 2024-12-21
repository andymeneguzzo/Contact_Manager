#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
public:
    Contact(const std::string& name, const std::string& phone, const std::string& email);

    void to_string() const;

private:
    std::string name;
    std::string phone;
    std::string email;
};

#endif // CONTACT_H