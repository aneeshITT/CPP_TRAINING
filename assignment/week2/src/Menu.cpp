#include <iostream>
#include "Menu.h"
#include "ValidInput.h"

int showMenu() {
    std::cout << "\n1. Addition\n";
    std::cout << "2. Multiplication\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter choice: ";

    int choice = getValidInt();

    while(choice < 1 || choice > 3) {
        std::cout << "Invalid choice! Try again: ";
        choice = getValidInt();
    }

    return choice;
}