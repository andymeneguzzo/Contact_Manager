#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include "Contact.h"

class FileManager {
public:
    void saveContacts(const std::string& filename, const std::vector<Contact>& contacts) const;
    std::vector<Contact> loadContacts(const std::string& filename);
    void exportToCSV(const std::string& filename, const std::vector<Contact>& contacts) const;
};

#endif // FILEMANAGER_H