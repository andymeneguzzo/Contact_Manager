#include "Contact.h"
#include "ContactManager.h"
#include "Database.h"
#include <iostream>
#include <string>

int main() {
    ContactManager manager;
    Database db("contacts.db");
    db.connect();

    int choice;
    do {
        std::cout << "\n=== Contact Manager ===\n"
                  << "1. Inserisci nuovo contatto\n"
                  << "2. Visualizza tutti i contatti\n"
                  << "3. Ordina contatti\n"
                  << "4. Filtra contatti\n"
                  << "0. Esci\n"
                  << "Scelta: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string name, phone, email, dob, gender, status, notes;
                std::string profession, company, jobPosition, companyAddress, officePhone;

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

                manager.addContact(name, phone, email, dob, gender, status, notes,
                                profession, company, jobPosition, companyAddress, officePhone);
                break;
            }
            case 2: {
                std::cout << "\n=== Lista Contatti ===\n";
                manager.displayContacts();
                break;
            }
            case 3: {
                int sortChoice;
                std::cout << "\n=== Ordinamento ===\n"
                          << "1. Per professione\n"
                          << "2. Per azienda\n"
                          << "3. Per posizione lavorativa\n"
                          << "Scelta: ";
                std::cin >> sortChoice;

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
                manager.displayContacts();
                break;
            }
            case 4: {
                int filterChoice;
                std::string filterValue;
                std::cout << "\n=== Filtro ===\n"
                          << "1. Per professione\n"
                          << "2. Per azienda\n"
                          << "3. Per posizione lavorativa\n"
                          << "Scelta: ";
                std::cin >> filterChoice;
                std::cin.ignore();

                std::cout << "Valore da cercare: ";
                std::getline(std::cin, filterValue);

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

                std::cout << "\n=== Risultati Filtro ===\n";
                for (const auto& contact : filteredContacts) {
                    contact.to_string();
                    std::cout << "------------------------\n";
                }
                break;
            }
        }
    } while (choice != 0);

    db.disconnect();
    return 0;
}