#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
public:
     Contact(const std::string& name, const std::string& phone, const std::string& email, 
            const std::string& dob, const std::string& gender, const std::string& status, 
            const std::string& notes, const std::string& profession, const std::string& company,
            const std::string& jobPosition, const std::string& companyAddress, 
            const std::string& officePhone, const std::string& category, const std::string& group);

    // Getters
    std::string getName() const;
    std::string getPhone() const;
    std::string getEmail() const;
    std::string getDob() const;
    std::string getGender() const;
    std::string getStatus() const;
    std::string getNotes() const;
    std::string getProfession() const;
    std::string getCompany() const;
    std::string getJobPosition() const;
    std::string getCompanyAddress() const;
    std::string getOfficePhone() const;

    // New Getters
    std::string getCategory() const;
    std::string getGroup() const;

    // Setters
    void setName(const std::string& name);
    void setPhone(const std::string& phone);
    void setEmail(const std::string& email);
    void setDob(const std::string& dob);
    void setGender(const std::string& gender);
    void setStatus(const std::string& status);
    void setNotes(const std::string& notes);
    void setProfession(const std::string& profession);
    void setCompany(const std::string& company);
    void setJobPosition(const std::string& jobPosition);
    void setCompanyAddress(const std::string& companyAddress);
    void setOfficePhone(const std::string& officePhone);

    // New Setters
    void setCategory(const std::string& category);
    void setGroup(const std::string& group);

    // Print contact information as a string
    void to_string() const;

private:
    std::string name;
    std::string phone;
    std::string email;
    std::string dob;    // Date of Birth
    std::string gender;
    std::string status; // Married, Engaged, Single
    std::string notes;  // Personal Notes
    std::string profession;
    std::string company;
    std::string jobPosition;
    std::string companyAddress;
    std::string officePhone;

    // New Attributes
    std::string category;
    std::string group;

};

#endif // CONTACT_H