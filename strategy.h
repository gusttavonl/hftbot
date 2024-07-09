#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include <iostream>
#include <numeric>
#include "market_data.h"

class Strategy {
public:
    std::vector<MarketData> data;
    double stop_loss;
    double stop_win;
    double entry_price;
    bool in_trade;

    Strategy(double stop_loss, double stop_win) 
        : stop_loss(stop_loss), stop_win(stop_win), in_trade(false) {}

    void onMarketData(const MarketData& md) {
        std::cout << "Received market data: " << md.price << std::endl;
        if (md.symbol == "EUR/USD") {
            data.push_back(md);
            if (data.size() >= 3) {
                execute();
            }
        }
    }

    void execute() {
        std::cout << "Executing strategy..." << std::endl;
        if (!in_trade) {
            if (isLocalMinimum()) {
                entry_price = data[data.size() - 2].price;
                in_trade = true;
                std::cout << "Buy signal generated at price: " << entry_price << std::endl;
            }
        } else {
            double current_price = data.back().price;
            std::cout << "Current price: " << current_price << ", Entry price: " << entry_price << std::endl;
            if (current_price <= entry_price - stop_loss) {
                std::cout << "Stop Loss triggered at price: " << current_price << std::endl;
                in_trade = false;
            } else if (current_price >= entry_price + stop_win) {
                std::cout << "Take Profit triggered at price: " << current_price << std::endl;
                in_trade = false;
            }
        }
        if (data.size() > 3) {
            data.erase(data.begin());
        }
    }

private:
    bool isLocalMinimum() {
        bool is_minimum = data[data.size() - 2].price < data[data.size() - 3].price &&
                          data[data.size() - 2].price < data.back().price;
        std::cout << "Checking for local minimum at " << data[data.size() - 2].price 
                  << " (previous: " << data[data.size() - 3].price 
                  << ", next: " << data.back().price 
                  << ") - is minimum: " << is_minimum << std::endl;
        return is_minimum;
    }
};

#endif // STRATEGY_H
