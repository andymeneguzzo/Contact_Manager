#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
public:
    Contact(const std::string& name, const std::string& phone, const std::string& email);

    void to_string() const;
    std::string getName() const;
    void setName(const std::string& name);
    void setPhone(const std::string& phone);
    void setEmail(const std::string& email);

private:
    std::string name;
    std::string phone;
    std::string email;
};

#endif // CONTACT_H