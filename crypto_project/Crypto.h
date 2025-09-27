/*************************************************************************/
/* File Name: crypto.h                                                   */
/* Author: Christopher Frias                                             */
/* Purpose: Defines the Crypto class for managing cryptocurrency data.  */
/*                                                                       */
/* Usage:                                                                */
/*   Include this header in your implementation files (e.g., crypto.cpp)*/
/*************************************************************************/
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