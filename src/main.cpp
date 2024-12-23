#include "Contact.h"
#include "ContactManager.h"
#include "Database.h"
#include <iostream>
#include <string>

void displayMenu() {
    // Display the main menu
    std::cout << "\n=== Contact Manager ===\n"
            << "1. Inserisci nuovo contatto\n"  // Insert new contact
            << "2. Visualizza tutti i contatti\n"  // View all contacts
            << "3. Ordina contatti\n"  // Sort contacts
            << "4. Filtra contatti\n"  // Filter contacts
            << "0. Esci\n"  // Exit
            << "Scelta: ";
}

void handelChoice(int choice, ContactManager& manager) {
    switch (choice) {
            case 1: {
                // Variables to store contact details
                std::string name, phone, email, dob, gender, status, notes;
                std::string profession, company, jobPosition, companyAddress, officePhone;

                // Prompt user to enter contact details
                std::cout << "\n=== Inserimento Nuovo Contatto ===\n";
                std::cout << "Nome: ";
                std::getline(std::cin, name);
                std::cout << "Telefono: ";
                std::getline(std::cin, phone);
                std::cout << "Email: ";
                std::getline(std::cin, email);
                std::cout << "Data di nascita: ";
                std::getline(std::cin, dob);
                std::cout << "Genere: ";
                std::getline(std::cin, gender);
                std::cout << "Stato: ";
                std::getline(std::cin, status);
                std::cout << "Note: ";
                std::getline(std::cin, notes);
                std::cout << "Professione: ";
                std::getline(std::cin, profession);
                std::cout << "Azienda: ";
                std::getline(std::cin, company);
                std::cout << "Posizione lavorativa: ";
                std::getline(std::cin, jobPosition);
                std::cout << "Indirizzo azienda: ";
                std::getline(std::cin, companyAddress);
                std::cout << "Telefono ufficio: ";
                std::getline(std::cin, officePhone);

                // Duplicate check and handling
                std::vector<Contact> duplicates = manager.findDuplicates(name, phone, email);
                if(!duplicates.empty()) {
                    std::cout << "\nAttenzione, sono stati rilevati contatti duplicati:\n";
                    for(const auto& dup : duplicates) {
                        dup.to_string();
                        std::cout << "------------------------\n";
                    }
                    std::string risposta;
                    std::cout << "Vuoi continuare con l'inserimento? (s/n): ";
                    std::getline(std::cin, risposta);
                    if(risposta != "s" || risposta != "S") {
                        std::cout << "Inserimento annullato\n";
                        break;
                    }
                }

                // Unique identifier for the contact requested
                std::cout << "Inserisci un identificatore unico per distinguere il contatto (es. numero o caratteri speciali): ";
                std::string identificatore;
                std::getline(std::cin, identificatore);
                name += identificatore;

                // Add the new contact to the manager
                manager.addContact(name, phone, email, dob, gender, status, notes,
                                profession, company, jobPosition, companyAddress, officePhone);
                break;
            }
            case 2: {
                // Display all contacts
                std::cout << "\n=== Lista Contatti ===\n";
                manager.displayContacts();
                break;
            }
            case 3: {
                // Prompt user to choose sorting criteria
                int sortChoice;
                std::cout << "\n=== Ordinamento ===\n"
                          << "1. Per professione\n"  // By profession
                          << "2. Per azienda\n"  // By company
                          << "3. Per posizione lavorativa\n"  // By job position
                          << "Scelta: ";
                std::cin >> sortChoice;

                // Sort contacts based on user's choice
                switch (sortChoice) {
                    case 1:
                        manager.sortByProfession();
                        break;
                    case 2:
                        manager.sortByCompany();
                        break;
                    case 3:
                        manager.sortByJobPosition();
                        break;
                }
                // Display sorted contacts
                manager.displayContacts();
                break;
            }
            case 4: {
                // Prompt user to choose filtering criteria
                int filterChoice;
                std::string filterValue;
                std::cout << "\n=== Filtro ===\n"
                          << "1. Per professione\n"  // By profession
                          << "2. Per azienda\n"  // By company
                          << "3. Per posizione lavorativa\n"  // By job position
                          << "Scelta: ";
                std::cin >> filterChoice;
                std::cin.ignore();  // Ignore the newline character left in the input buffer

                // Prompt user to enter the value to filter by
                std::cout << "Valore da cercare: ";
                std::getline(std::cin, filterValue);

                // Filter contacts based on user's choice
                std::vector<Contact> filteredContacts;
                switch (filterChoice) {
                    case 1:
                        filteredContacts = manager.filterByProfession(filterValue);
                        break;
                    case 2:
                        filteredContacts = manager.filterByCompany(filterValue);
                        break;
                    case 3:
                        filteredContacts = manager.filterByJobPosition(filterValue);
                        break;
                }

                // Display filtered contacts
                std::cout << "\n=== Risultati Filtro ===\n";
                for (const auto& contact : filteredContacts) {
                    contact.to_string();
                    std::cout << "------------------------\n";
                }
                break;
            }
        }
}

int main() {
    // Create a ContactManager object to manage contacts
    ContactManager manager;
    
    // Create a Database object and connect to the database
    Database db("contacts.db");
    db.connect();

    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();  // Ignore the newline character left in the input buffer

        handelChoice(choice, manager);
    } while (choice != 0);  // Repeat until user chooses to exit

    // Disconnect from the database
    db.disconnect();
    return 0;
}