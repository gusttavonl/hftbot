#include <benchmark/benchmark.h>
#include "strategy.h"

static void BM_Execute(benchmark::State& state) {
    Strategy strategy(0.0050, 0.0050);
    for (auto _ : state) {
        strategy.onMarketData(MarketData("EUR/USD", 1.1500));
        strategy.onMarketData(MarketData("EUR/USD", 1.1450));
        strategy.onMarketData(MarketData("EUR/USD", 1.1480));
        strategy.execute();
    }
}
BENCHMARK(BM_Execute);

BENCHMARK_MAIN();
