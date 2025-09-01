#include "Portfolio.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

void Portfolio::addCrypto(const Crypto& c) {
    holdings.push_back(c);
}

void Portfolio::display() const {
    cout << "Your Portfolio:\n";
    for (const auto& coin : holdings) {
        cout << coin.name << " (" << coin.symbol << "): "
             << coin.quantity << " coins * $" << coin.priceUSD
             << " = $" << coin.getValueUSD() << "\n";
    }
    cout << "Total Portfolio Value: $" << totalValue() << endl;
}

bool Portfolio::removeCrypto(const string& symbol) {
    for (auto it = holdings.begin(); it != holdings.end(); it++) {
        if (it->symbol == symbol) {
            holdings.erase(it);
            return true;
        }
    }
    return false;
}

double Portfolio::totalValue() const {
    double total = 0.0;
    for (const auto& coin : holdings) {
        total += coin.getValueUSD();
    }
    return total;
}

// Save portfolio to file
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

// Load portfolio from file
bool Portfolio::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) return false;

    holdings.clear();
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string name, symbol, qtyStr, priceStr;

        getline(ss, name, ',');
        getline(ss, symbol, ',');
        getline(ss, qtyStr, ',');
        getline(ss, priceStr, ',');

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
