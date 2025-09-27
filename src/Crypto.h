/*************************************************************************/
/* File Name: Crypto.h                                                   */
/* Author: Christopher Frias                                             */
/* Purpose: Declares the Crypto class, which represents a cryptocurrency */
/*          holding with name, symbol, quantity, and USD price.          */
/*                                                                       */
/* Usage:                                                                */
/*   Include this header in Portfolio.h / Portfolio.cpp and main.cpp.    */
/*   Requires: <string>                                                  */
/*************************************************************************/

#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>

class Crypto {
public:
std::string name;    // Full name of the crypto (e.g., "Bitcoin")
std::string symbol;  // Symbol shorthand (e.g., "BTC")
double quantity;     // Number of coins owned
double priceUSD;     // Price per coin in USD

// Constructor
Crypto(const std::string& name, const std::string& symbol, double quantity);

// Return total value in USD = quantity * priceUSD
double getValueUSD() const;

};

#endif // CRYPTO_H
