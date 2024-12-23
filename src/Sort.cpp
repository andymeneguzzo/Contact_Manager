#include "Sort.h"
#include <algorithm>

void Sort::sortByName(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getName() < b.getName();
    });
}

void Sort::sortByPhone(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getPhone() < b.getPhone();
    });
}

void Sort::sortByEmail(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getEmail() < b.getEmail();
    });
}

void Sort::sortByDob(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getDob() < b.getDob();
    });
}

void Sort::sortByGender(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getGender() < b.getGender();
    });
}

void Sort::sortByStatus(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getStatus() < b.getStatus();
    });
}

void Sort::sortByProfession(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getProfession() < b.getProfession();
    });
}

void Sort::sortByCompany(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getCompany() < b.getCompany();
    });
}

void Sort::sortByJobPosition(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getJobPosition() < b.getJobPosition();
    });
}

void Sort::sortByCompanyAddress(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getCompanyAddress() < b.getCompanyAddress();
    });
}

void Sort::sortByOfficePhone(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getOfficePhone() < b.getOfficePhone();
    });
}

void Sort::sortByCategory(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getCategory() < b.getCategory();
    });
}

void Sort::sortByGroup(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getGroup() < b.getGroup();
    });
}