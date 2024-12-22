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
        manager.addContact(contact.getName(), contact.getPhone(), contact.getEmail(),
                           contact.getDob(), contact.getGender(), contact.getStatus(), contact.getNotes());
    }
    db.disconnect();

    // Declare variables
    const Contact* contact = nullptr;
    std::string name, phone, email, dob, gender, status, notes;
    char choice;

    // Input data for new contacts while choice is 's' or 'S'
    do {
        std::cout << "Inserisci il nome del contatto: ";
        std::getline(std::cin, name);
        std::cout << "Inserisci il numero di telefono del contatto: ";
        std::getline(std::cin, phone);
        std::cout << "Inserisci l'email del contatto: ";
        std::getline(std::cin, email);
        std::cout << "Inserisci la data di nascita del contatto: ";
        std::getline(std::cin, dob);
        std::cout << "Inserisci il genere del contatto: ";
        std::getline(std::cin, gender);
        std::cout << "Inserisci lo stato del contatto (Married, Engaged, Single): ";
        std::getline(std::cin, status);
        std::cout << "Inserisci le note personali del contatto: ";
        std::getline(std::cin, notes);

        manager.addContact(name, phone, email, dob, gender, status, notes);

        std::cout << "Vuoi aggiungere un altro contatto? (s/n): ";
        std::cin >> choice;
        std::cin.ignore(); // Ignora il carattere newline rimasto nel buffer

    } while (choice == 's' || choice == 'S');

    // Once finished adding contacts, display contacts
    std::cout << "Contact List:" << std::endl;
    manager.displayContacts();

    // Sort and display contacts by name
    std::cout << "Sorted by Name:" << std::endl;
    manager.sortByName();
    manager.displayContacts();

    // Sort and display contacts by phone
    std::cout << "Sorted by Phone:" << std::endl;
    manager.sortByPhone();
    manager.displayContacts();

    // Sort and display contacts by email
    std::cout << "Sorted by Email:" << std::endl;
    manager.sortByEmail();
    manager.displayContacts();

    // Sort and display contacts by date of birth
    std::cout << "Sorted by Date of Birth:" << std::endl;
    manager.sortByDob();
    manager.displayContacts();

    // Sort and display contacts by gender
    std::cout << "Sorted by Gender:" << std::endl;
    manager.sortByGender();
    manager.displayContacts();

    // Sort and display contacts by status
    std::cout << "Sorted by Status:" << std::endl;
    manager.sortByStatus();
    manager.displayContacts();

    // Filter and display contacts by name
    std::cout << "Filtered by Name (Alice):" << std::endl;
    auto filteredByName = manager.filterByName("Alice");
    for (const auto& contact : filteredByName) {
        contact.to_string();
        std::cout << "-------------------" << std::endl;
    }

    // Filter and display contacts by phone
    std::cout << "Filtered by Phone (1234567890):" << std::endl;
    auto filteredByPhone = manager.filterByPhone("1234567890");
    for (const auto& contact : filteredByPhone) {
        contact.to_string();
        std::cout << "-------------------" << std::endl;
    }

    // Filter and display contacts by email
    std::cout << "Filtered by Email (example@example.com):" << std::endl;
    auto filteredByEmail = manager.filterByEmail("example@example.com");
    for (const auto& contact : filteredByEmail) {
        contact.to_string();
        std::cout << "-------------------" << std::endl;
    }

    // Filter and display contacts by date of birth
    std::cout << "Filtered by Date of Birth (1990-01-01):" << std::endl;
    auto filteredByDob = manager.filterByDob("1990-01-01");
    for (const auto& contact : filteredByDob) {
        contact.to_string();
        std::cout << "-------------------" << std::endl;
    }

    // Filter and display contacts by gender
    std::cout << "Filtered by Gender (Male):" << std::endl;
    auto filteredByGender = manager.filterByGender("Male");
    for (const auto& contact : filteredByGender) {
        contact.to_string();
        std::cout << "-------------------" << std::endl;
    }

    // Filter and display contacts by status
    std::cout << "Filtered by Status (Single):" << std::endl;
    auto filteredByStatus = manager.filterByStatus("Single");
    for (const auto& contact : filteredByStatus) {
        contact.to_string();
        std::cout << "-------------------" << std::endl;
    }

    return 0;
}