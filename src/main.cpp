#include "Contact.h"
#include "ContactManager.h"
#include "Database.h"
#include "TestInterface.h"

#include <iostream>
#include <string>

int main() {
    // Create a ContactManager object to manage contacts
    ContactManager manager;
    TestInterface interface;
    int choice;
    
    // Create a Database object and connect to the database
    Database db("contacts.db");
    db.connect();

    do {
        interface.displayMenu();
        std::cin >> choice;
        std::cin.ignore();  // Ignore the newline character left in the input buffer

        interface.handleChoice(choice, manager);
    } while (choice != 0);  // Repeat until user chooses to exit

    // Disconnect from the database
    db.disconnect();
    return 0;
}