#include "Contact.h"
#include "ContactManager.h"
#include "Database.h"
#include "TestInterface.h"

#include <iostream>
#include <string>

int main() {
    // Create a ContactManager object to manage contacts
    ContactManager manager;
    
    // Create a TestInterface object to handle user interactions
    TestInterface interface;
    int choice;
    
    // Create a Database object and connect to the database
    Database db("contacts.db");
    db.connect();

    do {
        // Display the menu to the user
        interface.displayMenu();
        
        // Get the user's choice
        std::cin >> choice;
        std::cin.ignore();  // Ignore the newline character left in the input buffer

        // Handle the user's choice
        interface.handleChoice(choice, manager);
    } while (choice != 0);  // Repeat until user chooses to exit

    // Disconnect from the database
    db.disconnect();
    
    return 0;
}