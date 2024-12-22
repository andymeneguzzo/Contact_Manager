#include "Contact.h"
#include "ContactManager.h"
#include "Database.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Function to generate a random string of given length
std::string generateRandomString(size_t length) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string randomString;
    for (size_t i = 0; i < length; ++i) {
        randomString += characters[rand() % characters.size()];
    }
    return randomString;
}

// Function to generate a random phone number
std::string generateRandomPhoneNumber() {
    std::string phoneNumber = "+39 ";
    for (int i = 0; i < 10; ++i) {
        phoneNumber += std::to_string(rand() % 10);
    }
    return phoneNumber;
}

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

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate 10 random contacts
    for (int i = 0; i < 10; ++i) {
        name = generateRandomString(8);
        phone = generateRandomPhoneNumber();
        email = generateRandomString(5) + "@andy.com";
        manager.addContact(name, phone, email);
    }



// CODE OMITTED TO TEST THE NEW FUNCTIONALITY WITH SINGULAR TESTS
/*
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
*/

    // Once finished adding contacts, display contacts
    std::cout << "Contact List:" << std::endl;
    manager.displayContacts();

    std::cout << "**** SORTING BY NAME ****" << std::endl;

    // Sort and display contacts by name
    std::cout << "Sorted by Name:" << std::endl;
    manager.sortByName();
    manager.displayContacts();

    std::cout << "**** SORTING BY PHONE ****" << std::endl;

    // Sort and display contacts by phone
    std::cout << "Sorted by Phone:" << std::endl;
    manager.sortByPhone();
    manager.displayContacts();

    std::cout << "**** SORTING BY EMAIL ****" << std::endl;

    // Sort and display contacts by email
    std::cout << "Sorted by Email:" << std::endl;
    manager.sortByEmail();
    manager.displayContacts();

    std::cout << "End of execution..." << std::endl;

    return 0;
}