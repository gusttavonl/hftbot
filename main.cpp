#include <iostream>
#include <cstdlib>
#include "trading_system.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <stop_loss> <stop_win>\n";
        return 1;
    }

    double stop_loss = std::atof(argv[1]);
    double stop_win = std::atof(argv[2]);

    std::cout << "Starting trading bot with stop_loss=" << stop_loss << " and stop_win=" << stop_win << std::endl;

    TradingSystem ts(stop_loss, stop_win);
    ts.run();

    return 0;
}
