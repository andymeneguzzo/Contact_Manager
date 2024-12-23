#include "Search.h"
#include "ContactManager.h"

const Contact* Search::searchByName(const std::vector<Contact>& contacts, const std::string& name) const {
    for (const auto& contact : contacts) {
        if (contact.getName() == name) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}

const Contact* Search::searchByPhone(const std::vector<Contact>& contacts, const std::string& phone) const {
    for (const auto& contact : contacts) {
        if (contact.getPhone() == phone) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}

const Contact* Search::searchByEmail(const std::vector<Contact>& contacts, const std::string& email) const {
    for (const auto& contact : contacts) {
        if (contact.getEmail() == email) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}

const Contact* Search::searchByDob(const std::vector<Contact>& contacts, const std::string& dob) const {
    for (const auto& contact : contacts) {
        if (contact.getDob() == dob) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}

const Contact* Search::searchByGender(const std::vector<Contact>& contacts, const std::string& gender) const {
    for (const auto& contact : contacts) {
        if (contact.getGender() == gender) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}

const Contact* Search::searchByStatus(const std::vector<Contact>& contacts, const std::string& status) const {
    for (const auto& contact : contacts) {
        if (contact.getStatus() == status) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}

const Contact* Search::searchByProfession(const std::vector<Contact>& contacts, const std::string& profession) const {
    for (const auto& contact : contacts) {
        if (contact.getProfession() == profession) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}

const Contact* Search::searchByCompany(const std::vector<Contact>& contacts, const std::string& company) const {
    for (const auto& contact : contacts) {
        if (contact.getCompany() == company) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}

const Contact* Search::searchByJobPosition(const std::vector<Contact>& contacts, const std::string& jobPosition) const {
    for (const auto& contact : contacts) {
        if (contact.getJobPosition() == jobPosition) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}

const Contact* Search::searchByCompanyAddress(const std::vector<Contact>& contacts, const std::string& companyAddress) const {
    for (const auto& contact : contacts) {
        if (contact.getCompanyAddress() == companyAddress) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}

const Contact* Search::searchByOfficePhone(const std::vector<Contact>& contacts, const std::string& officePhone) const {
    for (const auto& contact : contacts) {
        if (contact.getOfficePhone() == officePhone) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}

const Contact* Search::searchByCategory(const std::vector<Contact>& contacts, const std::string& category) const {
    for (const auto& contact : contacts) {
        if (contact.getCategory() == category) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}

const Contact* Search::searchByGroup(const std::vector<Contact>& contacts, const std::string& group) const {
    for (const auto& contact : contacts) {
        if (contact.getGroup() == group) {
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no contact is found
}