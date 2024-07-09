# High-Frequency Trading Bot for EUR/USD

## Overview
This project is a high-frequency trading (HFT) bot designed for trading the EUR/USD currency pair. The bot utilizes low-latency trading strategies, including pullback and local minimum detection, and integrates real-time market data using the Alpha Vantage API.


## Features
- **Low Latency Trading**: Employs advanced C++ techniques to minimize latency.
- **Real-Time Data Integration**: Fetches live market data from the Alpha Vantage API.
- **Customizable Parameters**: Allows configuration of stop loss and stop win levels via command-line arguments.
- **Pullback and Local Minimum Detection**: Implements a strategy to detect pullbacks and local minima for trading decisions.

## Technologies Used
- **C++**: Core programming language.
- **CMake**: Build system for managing the project.
- **libcurl**: Library for making HTTP requests to fetch real-time market data.
- **JSONCPP**: Library for parsing JSON responses from the API.
- **Google Benchmark**: Tool for measuring the performance of the trading strategy.

## Installation

### Prerequisites
Ensure you have the following libraries installed on your system:
- `libcurl`
- `libjsoncpp`
- `libbenchmark`

On Ubuntu, you can install them using:
```sh
sudo apt-get update
sudo apt-get install -y libcurl4-openssl-dev libjsoncpp-dev libbenchmark-dev
```

## Build Instructions

Clone the Repository:

```sh
git clone git@github.com:gusttavonl/hftbot.git
cd hftbot
```

Create a Build Directory and Compile:

```sh
mkdir build
cd build
cmake ..
make
```

## Usage

### Running the Trading Bot
To run the trading bot with specified stop loss and stop win levels:

```sh
./trading_bot <stop_loss> <stop_win>
# Example:
./trading_bot 0.0050 0.0050
```

### Running the Benchmark
To run the benchmark and measure the performance of the trading strategy:

```sh
./benchmark_bot
```