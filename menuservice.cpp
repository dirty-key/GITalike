#include <iostream>
#include <map>
#include <string>
#include "commitment.h"
#include "Makingfilesdirectories.h"


int main() {
    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Initialize a Repo" << std::endl;
        std::cout << "2. Commit" << std::endl;
        std::cout << "3. Load commit by ID" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
               make_dir();
               break;
            case 2:
                commitment();
                break;
            case 3:
               
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
                break;
        }
    }

    return 0;
}
