/*************************************************************************/
/* File Name: crypto.cpp                                                 */
/* Author: Christopher Frias                                             */
/* Purpose: Implements the Crypto class for managing cryptocurrency.   */
/*                                                                       */
/* Usage:                                                                */
/*   Compile with your main program and other modules.                  */
/*************************************************************************/
#include "Crypto.h"

Crypto::Crypto(const string& name, const string& symbol, double quantity)
    : name(name), symbol(symbol), quantity(quantity), priceUSD(0.0) {}

double Crypto::getValueUSD() const {
    return quantity * priceUSD;
}