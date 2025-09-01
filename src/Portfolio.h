#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <vector>
#include "Crypto.h"
using namespace std;

class Portfolio {
private:
    vector<Crypto> holdings;

public:
    void addCrypto(const Crypto& c);
    void display() const;
    double totalValue() const;
    bool removeCrypto(const string& symbol);

    // New functions
    bool saveToFile(const string& filename) const;
    bool loadFromFile(const string& filename);
};

#endif