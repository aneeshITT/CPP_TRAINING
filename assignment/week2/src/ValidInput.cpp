#include <iostream>
#include <limits>
#include "ValidInput.h"

int getValidInt() {
    int x;

    while(true) {
        if(std::cin >> x) {
            return x;
        }
        else if(std::cin.eof()) {
            std::cout << "\nEOF detected. Exiting...\n";
            exit(0);
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Enter integer again: ";
        }
    }
}