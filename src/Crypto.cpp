#include "Crypto.h"

Crypto::Crypto(const string& name, const string& symbol, double quantity)
    : name(name), symbol(symbol), quantity(quantity), priceUSD(0.0) {}

double Crypto::getValueUSD() const {
    return quantity * priceUSD;
}