#include "Filter.h"
#include <algorithm>

std::vector<Contact> Filter::filterByName(const std::vector<Contact>& contacts, const std::string& name) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&name](const Contact& contact) {
        return contact.getName() == name;
    });
    return result;
}

std::vector<Contact> Filter::filterByPhone(const std::vector<Contact>& contacts, const std::string& phone) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&phone](const Contact& contact) {
        return contact.getPhone() == phone;
    });
    return result;
}

std::vector<Contact> Filter::filterByEmail(const std::vector<Contact>& contacts, const std::string& email) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&email](const Contact& contact) {
        return contact.getEmail() == email;
    });
    return result;
}

std::vector<Contact> Filter::filterByDob(const std::vector<Contact>& contacts, const std::string& dob) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&dob](const Contact& contact) {
        return contact.getDob() == dob;
    });
    return result;
}

std::vector<Contact> Filter::filterByGender(const std::vector<Contact>& contacts, const std::string& gender) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&gender](const Contact& contact) {
        return contact.getGender() == gender;
    });
    return result;
}

std::vector<Contact> Filter::filterByStatus(const std::vector<Contact>& contacts, const std::string& status) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&status](const Contact& contact) {
        return contact.getStatus() == status;
    });
    return result;
}

std::vector<Contact> Filter::filterByProfession(const std::vector<Contact>& contacts, const std::string& profession) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&profession](const Contact& contact) {
        return contact.getProfession() == profession;
    });
    return result;
}

std::vector<Contact> Filter::filterByCompany(const std::vector<Contact>& contacts, const std::string& company) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&company](const Contact& contact) {
        return contact.getCompany() == company;
    });
    return result;
}

std::vector<Contact> Filter::filterByJobPosition(const std::vector<Contact>& contacts, const std::string& position) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&position](const Contact& contact) {
        return contact.getJobPosition() == position;
    });
    return result;
}

std::vector<Contact> Filter::filterByCompanyAddress(const std::vector<Contact>& contacts, const std::string& companyAddress) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&companyAddress](const Contact& contact) {
        return contact.getCompanyAddress() == companyAddress;
    });
    return result;
}

std::vector<Contact> Filter::filterByOfficePhone(const std::vector<Contact>& contacts, const std::string& officePhone) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&officePhone](const Contact& contact) {
        return contact.getOfficePhone() == officePhone;
    });
    return result;
}

std::vector<Contact> Filter::filterByCategory(const std::vector<Contact>& contacts, const std::string& category) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&category](const Contact& contact) {
        return contact.getCategory() == category;
    });
    return result;
}

std::vector<Contact> Filter::filterByGroup(const std::vector<Contact>& contacts, const std::string& group) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&group](const Contact& contact) {
        return contact.getGroup() == group;
    });
    return result;
}