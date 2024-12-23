#ifndef TESTINTERFACE_H
#define TESTINTERFACE_H

#include "ContactManager.h"
#include "Search.h"
#include "FileManager.h"

class TestInterface {
public:
    void displayMenu() const;
    void handleChoice(int choice, ContactManager& manager, Search& search, FileManager& fileManager) const;
};

#endif // TESTINTERFACE_H