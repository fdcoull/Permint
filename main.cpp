#include <iostream>
#include <limits>

void menu1() {
    std::cout << "Menu option 1\n";
}

void menu2() {
    std::cout << "Menu option 2\n";
}

void runMenu () {
    int choice = 0;

    while (choice != 3) {
        // Output menu
        std::cout << "---------------\n";
        std::cout << "Menu\n";
        std::cout << "1. Option 1\n";
        std::cout << "2. Option 2\n";
        std::cout << "3. Exit\n\n";

        // Validate input
        if (!(std::cin >> choice) || choice < 0 || choice > 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number within the range.\n\n";
            continue;
        }

        // Evaluate menu choice
        if (choice == 1) {
            menu1();
        } else if (choice == 2) {
            menu2();
        }
    }
}

int main() {
    runMenu();
    return 0;
}
