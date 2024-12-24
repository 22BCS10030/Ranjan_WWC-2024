#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>

// Struct to represent a trade
struct Trade {
    std::string timestamp;
    std::string stockSymbol;
    double tradePrice;
    int tradeVolume;

    // Constructor for initializing a trade
    Trade(const std::string& time, const std::string& symbol, double price, int volume)
        : timestamp(time), stockSymbol(symbol), tradePrice(price), tradeVolume(volume) {}
};

// Function to sort trades by timestamp
void sortByTimestamp(std::vector<Trade>& trades) {
    std::sort(trades.begin(), trades.end(), [](const Trade& a, const Trade& b) {
        return a.timestamp < b.timestamp;
    });
}

// Function to sort trades by stock symbol
void sortByStockSymbol(std::vector<Trade>& trades) {
    std::sort(trades.begin(), trades.end(), [](const Trade& a, const Trade& b) {
        return a.stockSymbol < b.stockSymbol;
    });
}

// Function to group trades by volume trends
std::map<int, std::vector<Trade>> groupByTradeVolume(const std::vector<Trade>& trades) {
    std::map<int, std::vector<Trade>> groupedTrades;
    for (const auto& trade : trades) {
        groupedTrades[trade.tradeVolume].push_back(trade);
    }
    return groupedTrades;
}

int main() {
    // Example list of trades
    std::vector<Trade> trades = {
        Trade("2024-12-24T10:15:00", "AAPL", 175.50, 100),
        Trade("2024-12-24T10:16:00", "GOOGL", 2820.00, 200),
        Trade("2024-12-24T10:14:00", "MSFT", 340.20, 150),
        Trade("2024-12-24T10:13:00", "AAPL", 176.00, 100),
        Trade("2024-12-24T10:17:00", "GOOGL", 2830.50, 300)
    };

    // Sort by timestamp
    sortByTimestamp(trades);
    std::cout << "Trades sorted by timestamp:\n";
    for (const auto& trade : trades) {
        std::cout << "Timestamp: " << trade.timestamp
                  << ", Stock Symbol: " << trade.stockSymbol
                  << ", Price: " << trade.tradePrice
                  << ", Volume: " << trade.tradeVolume << "\n";
    }

    // Sort by stock symbol
    sortByStockSymbol(trades);
    std::cout << "\nTrades sorted by stock symbol:\n";
    for (const auto& trade : trades) {
        std::cout << "Timestamp: " << trade.timestamp
                  << ", Stock Symbol: " << trade.stockSymbol
                  << ", Price: " << trade.tradePrice
                  << ", Volume: " << trade.tradeVolume << "\n";
    }

    // Group by trade volume
    auto groupedTrades = groupByTradeVolume(trades);
    std::cout << "\nTrades grouped by trade volume:\n";
    for (const auto& [volume, group] : groupedTrades) {
        std::cout << "Volume: " << volume << "\n";
        for (const auto& trade : group) {
            std::cout << "    Timestamp: " << trade.timestamp
                      << ", Stock Symbol: " << trade.stockSymbol
                      << ", Price: " << trade.tradePrice << "\n";
        }
    }

    return 0;
}

