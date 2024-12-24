#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Structure to represent an advertisement
struct Advertisement {
    std::string advertiserName;  // Name of the advertiser
    double bidAmount;            // Amount bid for the ad (higher is better)
    double engagementRate;       // User engagement rate (e.g., click-through rate, out of 100%)
    double remainingBudget;      // Remaining budget for the ad
    double priorityScore;        // Computed score for prioritization

    // Constructor for easier initialization
    Advertisement(std::string name, double bid, double engagement, double budget)
        : advertiserName(name), bidAmount(bid), engagementRate(engagement), remainingBudget(budget), priorityScore(0) {}
};

// Function to calculate the priority score for advertisements
double calculatePriorityScore(double bidAmount, double engagementRate, double remainingBudget) {
    // Example logic: weight bid amount, engagement rate, and budget
    return bidAmount * 0.5 + engagementRate * 0.3 + (remainingBudget > 0 ? 0.2 * remainingBudget : 0);
}

// Function to sort advertisements based on priority
void sortAdvertisements(std::vector<Advertisement>& ads) {
    std::sort(ads.begin(), ads.end(), [](const Advertisement& a, const Advertisement& b) {
        return a.priorityScore > b.priorityScore; // Higher score first
    });
}

int main() {
    // Example dataset of advertisements
    std::vector<Advertisement> ads = {
        Advertisement("Advertiser A", 5.0, 70.0, 1000.0),
        Advertisement("Advertiser B", 8.0, 50.0, 500.0),
        Advertisement("Advertiser C", 4.0, 90.0, 800.0),
        Advertisement("Advertiser D", 7.0, 60.0, 1200.0),
        Advertisement("Advertiser E", 6.0, 85.0, 0.0)
    };

    // Calculate priority scores for each advertisement
    for (auto& ad : ads) {
        ad.priorityScore = calculatePriorityScore(ad.bidAmount, ad.engagementRate, ad.remainingBudget);
    }

    // Sort the advertisements by priority
    sortAdvertisements(ads);

    // Output the sorted advertisements
    std::cout << "Sorted Advertisements:\n";
    for (const auto& ad : ads) {
        std::cout << "Advertiser: " << ad.advertiserName
                  << ", Bid Amount: " << ad.bidAmount
                  << ", Engagement Rate: " << ad.engagementRate
                  << ", Remaining Budget: " << ad.remainingBudget
                  << ", Priority Score: " << ad.priorityScore << "\n";
    }

    // Simulate a new advertisement submission
    std::cout << "\nNew Advertisement Submission:\n";
    ads.emplace_back("Advertiser F", 9.0, 75.0, 600.0);

    // Recalculate scores and re-sort the advertisements
    for (auto& ad : ads) {
        ad.priorityScore = calculatePriorityScore(ad.bidAmount, ad.engagementRate, ad.remainingBudget);
    }
    sortAdvertisements(ads);

    // Output the updated sorted advertisements
    std::cout << "\nUpdated Sorted Advertisements:\n";
    for (const auto& ad : ads) {
        std::cout << "Advertiser: " << ad.advertiserName
                  << ", Bid Amount: " << ad.bidAmount
                  << ", Engagement Rate: " << ad.engagementRate
                  << ", Remaining Budget: " << ad.remainingBudget
                  << ", Priority Score: " << ad.priorityScore << "\n";
    }

    return 0;
}
