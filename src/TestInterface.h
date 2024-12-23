#ifndef TESTINTERFACE_H
#define TESTINTERFACE_H

#include "ContactManager.h"

class TestInterface {
public:
    void displayMenu() const;
    void handleChoice(int choice, ContactManager& manager) const;
};

#endif // TESTINTERFACE_H