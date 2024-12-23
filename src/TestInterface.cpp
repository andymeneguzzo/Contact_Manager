#include "TestInterface.h"
#include <iostream>
#include <string>
#include "ContactManager.h"
#include "Search.h"

void TestInterface::displayMenu() const {
    std::cout << "\n=== Contact Manager ===\n"
              << "1. Inserisci nuovo contatto\n"
              << "2. Visualizza tutti i contatti\n"
              << "3. Ordina contatti\n"
              << "4. Filtra contatti\n"
              << "5. Statistiche\n"
              << "6. Esporta contatti in CSV\n"
              << "7. Importa contatti da CSV\n"
              << "0. Esci\n"
              << "Scelta: ";
}

void TestInterface::handleChoice(int choice, ContactManager& manager, Search& search, FileManager& fileManager) const {
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

            std::vector<Contact> duplicates = manager.findDuplicates(name, phone, email);
            if (!duplicates.empty()) {
                std::cout << "\nAttenzione: Sono stati rilevati contatti duplicati:\n";
                for (const auto& dup : duplicates) {
                    dup.to_string();
                    std::cout << "-------------------\n";
                }
                std::string risposta;
                std::cout << "Vuoi procedere con l'inserimento del duplicato? (s/n): ";
                std::getline(std::cin, risposta);
                if (risposta != "s" && risposta != "S") {
                    std::cout << "Inserimento annullato.\n";
                    break;
                }
                std::cout << "Inserisci un identificatore unico per distinguere il contatto (es. numero o caratteri speciali): ";
                std::string identificatore;
                std::getline(std::cin, identificatore);
                name += identificatore;
            }

            manager.addContact(name, phone, email, dob, gender, status, notes,
                               profession, company, jobPosition, companyAddress, officePhone);
            break;
        }
        case 2:
            manager.displayContacts();
            break;
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
                    manager.sorter.sortByProfession(manager.contacts);
                    break;
                case 2:
                    manager.sorter.sortByCompany(manager.contacts);
                    break;
                case 3:
                    manager.sorter.sortByJobPosition(manager.contacts);
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
                    filteredContacts = manager.filter.filterByProfession(manager.contacts, filterValue);
                    break;
                case 2:
                    filteredContacts = manager.filter.filterByCompany(manager.contacts, filterValue);
                    break;
                case 3:
                    filteredContacts = manager.filter.filterByJobPosition(manager.contacts, filterValue);
                    break;
            }

            std::cout << "\n=== Risultati Filtro ===\n";
            for (const auto& contact : filteredContacts) {
                contact.to_string();
                std::cout << "------------------------\n";
            }
            break;
        }
        case 5:
            manager.stats.generateStatistics(manager.contacts);
            break;
        case 6: {
            std::string filename;
            std::cout << "Inserisci il nome del file CSV: ";
            std::getline(std::cin, filename);
            manager.fileManager.exportToCSV(filename, manager.contacts);
            break;
        }
        case 7: {
            std::string filename;
            std::cout << "Inserisci il nome del file CSV: ";
            std::getline(std::cin, filename);
            std::vector<Contact> importedContacts = fileManager.importFromCSV(filename);
            for (const auto& contact : importedContacts) {
                manager.addContact(contact.getName(), contact.getPhone(), contact.getEmail(), contact.getDob(), contact.getGender(), contact.getStatus(), contact.getNotes(), contact.getProfession(), contact.getCompany(), contact.getJobPosition(), contact.getCompanyAddress(), contact.getOfficePhone());
            }
            std::cout << "Contatti importati con successo da " << filename << std::endl;
            break;
        }
        case 0:
            std::cout << "Uscita...\n";
            break;
        default:
            std::cout << "Scelta non valida. Riprova.\n";
    }
}