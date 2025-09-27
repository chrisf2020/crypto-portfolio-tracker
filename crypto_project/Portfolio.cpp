/*************************************************************************/
/* File Name: Portfolio.cpp                                               */
/* Author: Christopher Frias                                              */
/* Purpose: Implements the Portfolio class methods for managing a         */
/*          collection of cryptocurrencies. Provides functionality to    */
/*          add, display, remove, save, and load cryptos in the portfolio.*/
/*                                                                       */
/* Usage:                                                                */
/*   Used internally by main.cpp to handle portfolio operations.          */
/*   Requires: Portfolio.h, Crypto.h                                      */
/*                                                                       */
/*************************************************************************/

#include "Portfolio.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

// Add a crypto to the portfolio
void Portfolio::addCrypto(const Crypto& c) {
    holdings.push_back(c);
}

// Display all cryptos and total value
void Portfolio::display() const {
cout << "Your Portfolio:\n";
for (const auto& coin : holdings) {
    cout << coin.name << " (" << coin.symbol << "): "
    << coin.quantity << " coins * $" << coin.priceUSD
    << " = $" << coin.getValueUSD() << "\n";
    }
cout << "Total Portfolio Value: $" << totalValue() << endl;
}

// Remove a crypto by symbol
bool Portfolio::removeCrypto(const string& symbol) {
for (auto it = holdings.begin(); it != holdings.end(); it++) {
    if (it->symbol == symbol) {
        holdings.erase(it);
        return true; // successfully removed
        }  
    }
return false; // not found
}

// Calculate total value of portfolio
double Portfolio::totalValue() const {
double total = 0.0;
for (const auto& coin : holdings) {
    total += coin.getValueUSD();
    }
return total;
}

// Save portfolio to a text file
bool Portfolio::saveToFile(const string& filename) const {
ofstream out(filename);
if (!out.is_open()) return false;

for (const auto& coin : holdings) {
    out << coin.name << ","
        << coin.symbol << ","
        << fixed << setprecision(8) << coin.quantity << ","
        << fixed << setprecision(2) << coin.priceUSD << "\n";
    }
return true;

}

// Load portfolio from a text file
bool Portfolio::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) return false;


    holdings.clear(); // reset portfolio
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string name, symbol, qtyStr, priceStr;
        getline(ss, name, ',');
        getline(ss, symbol, ',');
        getline(ss, qtyStr, ',');
        getline(ss, priceStr, ',');

    // Only add if all fields are valid
    if (!name.empty() && !symbol.empty() && !qtyStr.empty() && !priceStr.empty()) {
        double qty = stod(qtyStr);
        double price = stod(priceStr);
        Crypto c(name, symbol, qty);
        c.priceUSD = price;
        holdings.push_back(c);
    }
}
return true;

}
