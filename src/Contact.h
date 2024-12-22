#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
public:
    Contact(const std::string& name, const std::string& phone, const std::string& email,
            const std::string& dob, const std::string& gender, const std::string& status, const std::string& notes);

    // Getters
    std::string getName() const;
    std::string getPhone() const;
    std::string getEmail() const;
    std::string getDob() const;
    std::string getGender() const;
    std::string getStatus() const;
    std::string getNotes() const;

    // Setters
    void setName(const std::string& name);
    void setPhone(const std::string& phone);
    void setEmail(const std::string& email);
    void setDob(const std::string& dob);
    void setGender(const std::string& gender);
    void setStatus(const std::string& status);
    void setNotes(const std::string& notes);

    void to_string() const;

private:
    std::string name;
    std::string phone;
    std::string email;
    std::string dob;    // Date of Birth
    std::string gender;
    std::string status; // Married, Engaged, Single
    std::string notes;  // Personal Notes
};

#endif // CONTACT_H