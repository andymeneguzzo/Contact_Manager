#include "Contact.h"
#include "ContactManager.h"
#include "Database.h"
#include "FileManager.h"
#include "Search.h"
#include "TestInterface.h"

#include <iostream>
#include <string>

int main() {
    // Crea un oggetto ContactManager per gestire i contatti
    ContactManager manager;
    
    // Crea un oggetto TestInterface per gestire le interazioni con l'utente
    TestInterface interface;
    int choice;
    
    // Crea un oggetto Database e connettiti al database
    Database db("contacts.db");
    db.connect();

    // Crea un oggetto FileManager per gestire le operazioni sui file
    FileManager fileManager;

    // Crea un oggetto Search per gestire le ricerche
    Search search;

    do {
        // Mostra il menu all'utente
        interface.displayMenu();
        
        // Ottieni la scelta dell'utente
        std::cin >> choice;
        interface.handleChoice(choice, manager, search, fileManager);
    } while (choice != 0);  // Ripeti fino a quando l'utente non sceglie di uscire

    // Disconnettiti dal database
    db.disconnect();
    
    return 0;
}