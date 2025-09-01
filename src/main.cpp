#include <iostream>
#include "Crypto.h"
#include "Portfolio.h"

using namespace std;

int main() {
    Portfolio myPortfolio;
    int choice;

    while (true) {
        cout << "\n=== Crypto Portfolio Menu ===\n";
        cout << "1. Add a crypto\n";
        cout << "2. View portfolio\n";
        cout << "3. Remove a crypto\n";
        cout << "4. Save portfolio\n";
        cout << "5. Load portfolio\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, symbol;
            double quantity, price;

            cout << "Enter coin name: ";
            cin >> ws; // eat newline
            getline(cin, name);

            cout << "Enter symbol (e.g. btc): ";
            cin >> symbol;

            cout << "Enter quantity owned: ";
            cin >> quantity;

            cout << "Enter current price (USD): ";
            cin >> price;

            Crypto newCoin(name, symbol, quantity);
            newCoin.priceUSD = price;

            myPortfolio.addCrypto(newCoin);
            cout << "Coin added.\n";

        } else if (choice == 2) {
            myPortfolio.display();

        } else if (choice == 3) {
            string symbol;
            cout << "Enter symbol of crypto to remove: ";
            cin >> symbol;

            if (myPortfolio.removeCrypto(symbol)) {
                cout << "Removed successfully.\n";
            } else {
                cout << "Could not find that crypto.\n";
            }

        } else if (choice == 4) {
            if (myPortfolio.saveToFile("portfolio.txt"))
                cout << "Portfolio saved.\n";
            else
                cout << "Failed to save.\n";

        } else if (choice == 5) {
            if (myPortfolio.loadFromFile("portfolio.txt"))
                cout << "Portfolio loaded.\n";
            else
                cout << "Failed to load.\n";

        } else if (choice == 6) {
            cout << "Goodbye.\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
