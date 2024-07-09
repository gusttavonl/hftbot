#ifndef MARKET_DATA_H
#define MARKET_DATA_H

#include <string>

class MarketData {
public:
    std::string symbol;
    double price;
    MarketData(const std::string& sym, double p) : symbol(sym), price(p) {}
};

#endif // MARKET_DATA_H
