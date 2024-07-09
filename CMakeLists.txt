cmake_minimum_required(VERSION 3.10)
project(TradingBot)

set(CMAKE_CXX_STANDARD 11)

find_package(benchmark REQUIRED)
find_package(CURL REQUIRED)
find_package(jsoncpp REQUIRED)

add_executable(trading_bot main.cpp)
add_executable(benchmark_bot benchmark.cpp)

target_link_libraries(trading_bot CURL::libcurl jsoncpp_lib)
target_link_libraries(benchmark_bot benchmark::benchmark)
