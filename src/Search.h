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
};

#endif // SEARCH_H