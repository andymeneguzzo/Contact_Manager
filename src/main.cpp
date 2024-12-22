#include "Contact.h"
#include "ContactManager.h"

#include <iostream>
#include <string>

int main() {
    ContactManager manager;
    manager.loadContacts("contacts.txt");
    const Contact* contact = nullptr;

    std::string name, phone, email;
    char choice;

    do {
        std::cout << "Inserisci il nome del contatto: ";
        std::getline(std::cin, name);
        std::cout << "Inserisci il numero di telefono del contatto: ";
        std::getline(std::cin, phone);
        std::cout << "Inserisci l'email del contatto: ";
        std::getline(std::cin, email);

        manager.addContact(name, phone, email);

        std::cout << "Vuoi aggiungere un altro contatto? (s/n): ";
        std::cin >> choice;
        std::cin.ignore(); // Ignora il carattere newline rimasto nel buffer

    } while (choice == 's' || choice == 'S');

    std::cout << "Contact List:" << std::endl;
    manager.displayContacts();

/*
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
*/

    return 0;
}