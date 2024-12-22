#include "Contact.h"
#include "ContactManager.h"

#include <iostream>

int main() {
    ContactManager manager;
    manager.loadContacts("contacts.txt");
    const Contact* contact = nullptr;
/*
    // Aggiungi 8 contatti di esempio
    manager.addContact("John Doe", "555-555-5555", "john.doe@example.com");
    manager.addContact("Jane Austen", "555-555-5556", "jane.austen@example.com");
    manager.addContact("Alice Wonderland", "555-555-5557", "alice.wonderland@example.com");
    manager.addContact("Bob Builder", "555-555-5558", "bob.builder@example.com");
    manager.addContact("Charlie Brown", "555-555-5559", "charlie.brown@example.com");
    manager.addContact("David Copperfield", "555-555-5560", "david.copperfield@example.com");
    manager.addContact("Eve Online", "555-555-5561", "eve.online@example.com");
    manager.addContact("Frank Sinatra", "555-555-5562", "frank.sinatra@example.com");
*/
    std::cout << "Contact List:" << std::endl;
    manager.displayContacts();

    // Test ricerca per nome
    std::string searchName = "Alice Wonderland";
    contact = manager.searchByName(searchName);
    if (contact) {
        std::cout << "Found contact by name (" << searchName << "):" << std::endl;
        contact->to_string();
    } else {
        std::cout << "Contact not found by name (" << searchName << ")." << std::endl;
    }

    // Test ricerca per numero di telefono
    std::string searchPhone = "555-555-5560";
    contact = manager.searchByPhone(searchPhone);
    if (contact) {
        std::cout << "Found contact by phone (" << searchPhone << "):" << std::endl;
        contact->to_string();
    } else {
        std::cout << "Contact not found by phone (" << searchPhone << ")." << std::endl;
    }

    // Test ricerca per email
    std::string searchEmail = "eve.online@example.com";
    contact = manager.searchByEmail(searchEmail);
    if (contact) {
        std::cout << "Found contact by email (" << searchEmail << "):" << std::endl;
        contact->to_string();
    } else {
        std::cout << "Contact not found by email (" << searchEmail << ")." << std::endl;
    }

    return 0;
}