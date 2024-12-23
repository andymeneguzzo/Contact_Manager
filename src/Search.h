#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <string>
#include "Contact.h"

class Search {
public:
    const Contact* searchByName(const std::vector<Contact>& contacts, const std::string& name) const;
    const Contact* searchByPhone(const std::vector<Contact>& contacts, const std::string& phone) const;
    const Contact* searchByEmail(const std::vector<Contact>& contacts, const std::string& email) const;
    const Contact* searchByDob(const std::vector<Contact>& contacts, const std::string& dob) const;
    const Contact* searchByGender(const std::vector<Contact>& contacts, const std::string& gender) const;
    const Contact* searchByStatus(const std::vector<Contact>& contacts, const std::string& status) const;
    const Contact* searchByProfession(const std::vector<Contact>& contacts, const std::string& profession) const;
    const Contact* searchByCompany(const std::vector<Contact>& contacts, const std::string& company) const;
    const Contact* searchByJobPosition(const std::vector<Contact>& contacts, const std::string& jobPosition) const;
    const Contact* searchByCompanyAddress(const std::vector<Contact>& contacts, const std::string& companyAddress) const;
    const Contact* searchByOfficePhone(const std::vector<Contact>& contacts, const std::string& officePhone) const;
    const Contact* searchByCategory(const std::vector<Contact>& contacts, const std::string& category) const;
    const Contact* searchByGroup(const std::vector<Contact>& contacts, const std::string& group) const;
};

#endif // SEARCH_H