#include "Contact.h"
#include "ContactManager.h"

#include <iostream>

int main() {
    ContactManager manager;

    manager.addContact("John Doe", "555-555-5555", "john.doe@example.com");
    std::cout << "Contact List (before modification):" << std::endl;
    manager.displayContacts();

    manager.editContact("John Doe", "Jane Austen", "555-555-5556", "jane.austen@example.com");
    std::cout << "Contact List (after modification):" << std::endl;
    manager.displayContacts();

    manager.removeContact("Jane Austen");
    std::cout << "Contact List (after removal):" << std::endl; // expected output: "No contacts to display."
    manager.displayContacts();

    return 0;
}