#include "Contact.h"
#include "ContactManager.h"
#include "Database.h"

#include <iostream>
#include <string>

int main() {
    // Declare manager and database objects
    ContactManager manager;
    Database db("contacts.db");

    // Initialize database and load contacts
    db.connect();
    manager.loadContacts("contacts.txt");
    auto contacts = db.getAllContacts();
    for (const auto& contact : contacts) {
        manager.addContact(contact.getName(), contact.getPhone(), contact.getEmail());
    }
    db.disconnect();

    // Declare variables
    const Contact* contact = nullptr;
    std::string name, phone, email;
    char choice;

    // Input data for new contacts while choice is 's' or 'S'
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

    // Once finished adding contacts, display contacts
    std::cout << "Contact List:" << std::endl;
    manager.displayContacts();

    return 0;
}