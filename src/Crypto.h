#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
using namespace std;

class Crypto {
public:
    string name;
    string symbol;
    double quantity;
    double priceUSD;

    Crypto(const string& name, const string& symbol, double quantity);

    double getValueUSD() const;
};

#endif