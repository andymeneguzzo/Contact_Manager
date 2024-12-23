#ifndef SORT_H
#define SORT_H

#include <vector>
#include "Contact.h"

class Sort {
public:
    void sortByName(std::vector<Contact>& contacts);
    void sortByPhone(std::vector<Contact>& contacts);
    void sortByEmail(std::vector<Contact>& contacts);
    void sortByDob(std::vector<Contact>& contacts);
    void sortByGender(std::vector<Contact>& contacts);
    void sortByStatus(std::vector<Contact>& contacts);
    void sortByProfession(std::vector<Contact>& contacts);
    void sortByCompany(std::vector<Contact>& contacts);
    void sortByJobPosition(std::vector<Contact>& contacts);
};

#endif // SORT_H