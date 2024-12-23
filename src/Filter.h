#ifndef FILTER_H
#define FILTER_H

#include <vector>
#include <string>
#include "Contact.h"

class Filter {
public:
    std::vector<Contact> filterByName(const std::vector<Contact>& contacts, const std::string& name) const;
    std::vector<Contact> filterByPhone(const std::vector<Contact>& contacts, const std::string& phone) const;
    std::vector<Contact> filterByEmail(const std::vector<Contact>& contacts, const std::string& email) const;
    std::vector<Contact> filterByDob(const std::vector<Contact>& contacts, const std::string& dob) const;
    std::vector<Contact> filterByGender(const std::vector<Contact>& contacts, const std::string& gender) const;
    std::vector<Contact> filterByStatus(const std::vector<Contact>& contacts, const std::string& status) const;
    std::vector<Contact> filterByProfession(const std::vector<Contact>& contacts, const std::string& profession) const;
    std::vector<Contact> filterByCompany(const std::vector<Contact>& contacts, const std::string& company) const;
    std::vector<Contact> filterByJobPosition(const std::vector<Contact>& contacts, const std::string& position) const;
    std::vector<Contact> filterByCompanyAddress(const std::vector<Contact>& contacts, const std::string& companyAddress) const;
    std::vector<Contact> filterByOfficePhone(const std::vector<Contact>& contacts, const std::string& officePhone) const;
    std::vector<Contact> filterByCategory(const std::vector<Contact>& contacts, const std::string& category) const;
    std::vector<Contact> filterByGroup(const std::vector<Contact>& contacts, const std::string& group) const;
};

#endif // FILTER_H