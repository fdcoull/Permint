#include <iostream>
#include <limits>
#include <sodium.h>

void menu1() {
    std::cout << "Generating keypair...\n";

    unsigned char public_key[crypto_kx_PUBLICKEYBYTES];
    unsigned char secret_key[crypto_kx_SECRETKEYBYTES];

    // Generate X25519 keypair
    crypto_kx_keypair(public_key, secret_key);

    // Output public in hex
    std::cout << "Public key:\n";

    for (int i = 0; i < sizeof(public_key); i++) {
        printf("%02x", public_key[i]);
    }

    // Output private key in hex
    std::cout << "\nPrivate key:\n";

    for (int i = 0; i < sizeof(secret_key); i++) {
        printf("%02x", secret_key[i]);
    }

    std::cout << '\n';

    sodium_memzero(secret_key, sizeof(secret_key));
}

void menu2() {
    std::cout << "Menu option 2\n";
}

void runMenu () {
    int choice = 0;

    // Check for sodium
    if (sodium_init() < 0) {
        return;
    }

    while (choice != 3) {
        // Output menu
        std::cout << "---------------\n";
        std::cout << "Menu\n";
        std::cout << "1. Create a key pair\n";
        std::cout << "2. Option 2\n";
        std::cout << "3. Exit\n";
        std::cout << "---------------\n";

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
