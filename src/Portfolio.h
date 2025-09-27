/*************************************************************************/
/* File Name: Portfolio.h                                                */
/* Author: Christopher Frias                                              */
/* Purpose: Declares the Portfolio class, which manages a collection of  */
/*          Crypto objects. Provides operations to add, display, remove, */
/*          save, and load cryptocurrencies.                             */
/*                                                                       */
/* Usage:                                                                */
/*   Include this header in main.cpp and link with Portfolio.cpp.        */
/*   Requires: Crypto.h                                                  */
/*************************************************************************/

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <vector>
#include <string>
#include "Crypto.h"

class Portfolio {
private:
    std::vector<Crypto> holdings;  // List of cryptocurrencies in the portfolio

public:
    // Add a crypto to the portfolio
    void addCrypto(const Crypto& c);

    // Display all cryptos and total value
    void display() const;

    // Get total USD value of the portfolio
    double totalValue() const;

    // Remove a crypto by its symbol
    bool removeCrypto(const std::string& symbol);

    // Save portfolio data to a text file
    bool saveToFile(const std::string& filename) const;

    // Load portfolio data from a text file
    bool loadFromFile(const std::string& filename);
};

#endif // PORTFOLIO_H
