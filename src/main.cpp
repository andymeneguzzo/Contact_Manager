#include "Contact.h"
#include "ContactManager.h"

#include <iostream>

int main() {
    ContactManager manager;

    manager.addContact("John Doe", "555-555-5555", "john.doe@example.com");
    std::cout << "Contact List (before modification):" << std::endl;
    manager.displayContacts();

    return 0;
}