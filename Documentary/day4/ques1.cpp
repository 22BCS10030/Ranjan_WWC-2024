#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Struct to represent a transaction
struct Transaction {
    std::string transactionID;
    double amount;
    int frequency;
    std::string location;
    double suspiciousnessScore;

    // Constructor for initializing a transaction
    Transaction(const std::string& id, double amt, int freq, const std::string& loc, double score)
        : transactionID(id), amount(amt), frequency(freq), location(loc), suspiciousnessScore(score) {}
};

// Function to calculate the suspiciousness score (can be customized as needed)
double calculateSuspiciousnessScore(double amount, int frequency, const std::string& location) {
    // Example formula combining factors
    double locationWeight = 1.0; // Adjust based on the riskiness of location (dummy value for now)
    return (amount * 0.7) + (frequency * 0.2) + (locationWeight * 0.1);
}

// Function to sort transactions by suspiciousness score
void sortTransactions(std::vector<Transaction>& transactions) {
    std::sort(transactions.begin(), transactions.end(), [](const Transaction& a, const Transaction& b) {
        return a.suspiciousnessScore > b.suspiciousnessScore; // Descending order
    });
}

int main() {
    // Example list of transactions
    std::vector<Transaction> transactions = {
        Transaction("TXN001", 5000.0, 10, "New York", calculateSuspiciousnessScore(5000.0, 10, "New York")),
        Transaction("TXN002", 200.0, 50, "Los Angeles", calculateSuspiciousnessScore(200.0, 50, "Los Angeles")),
        Transaction("TXN003", 10000.0, 5, "San Francisco", calculateSuspiciousnessScore(10000.0, 5, "San Francisco")),
        Transaction("TXN004", 700.0, 20, "Chicago", calculateSuspiciousnessScore(700.0, 20, "Chicago"))
    };

    // Sort transactions by suspiciousness score
    sortTransactions(transactions);

    // Display sorted transactions
    std::cout << "Sorted Transactions by Suspiciousness Score:\n";
    for (const auto& txn : transactions) {
        std::cout << "Transaction ID: " << txn.transactionID
                  << ", Amount: " << txn.amount
                  << ", Frequency: " << txn.frequency
                  << ", Location: " << txn.location
                  << ", Suspiciousness Score: " << txn.suspiciousnessScore << "\n";
    }

    return 0;
}
