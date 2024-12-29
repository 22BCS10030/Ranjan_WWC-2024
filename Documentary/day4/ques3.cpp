#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// Structure to represent a catalog item (movie or TV show)
struct CatalogItem {
    std::string title;          // Title of the item
    int totalViews;             // Total number of views
    double userRating;          // Average user rating (out of 10)
    int releaseYear;            // Release year
    double trendingScore;       // Computed score for trending content

    // Constructor for easier initialization
    CatalogItem(std::string t, int views, double rating, int year)
        : title(t), totalViews(views), userRating(rating), releaseYear(year), trendingScore(0) {}
};

// Function to calculate the trending score for catalog items
double calculateTrendingScore(int totalViews, double userRating, int releaseYear) {
    // Example logic: combine views, ratings, and recency with specific weights
    int currentYear = 2024;
    double recencyFactor = std::exp(-(currentYear - releaseYear) / 5.0); // Exponential decay for recency
    return totalViews * 0.5 + userRating * 20.0 + recencyFactor * 100.0;
}

// Function to calculate relevance score for personalized recommendations
double calculateRelevance(const CatalogItem& item, const std::vector<std::string>& userHistory) {
    // Example logic: match titles partially with user history
    int matchScore = 0;
    for (const auto& historyItem : userHistory) {
        if (item.title.find(historyItem) != std::string::npos) {
            matchScore += 10; // Assign higher score for title matches
        }
    }
    return item.trendingScore + matchScore;
}

int main() {
    // Example dataset of catalog items
    std::vector<CatalogItem> catalog = {
        CatalogItem("Popular Movie", 500000, 8.5, 2021),
        CatalogItem("New Release", 200000, 9.0, 2023),
        CatalogItem("Classic Hit", 1000000, 9.5, 1995),
        CatalogItem("Trending Show", 300000, 7.8, 2022),
        CatalogItem("Underrated Gem", 150000, 8.8, 2020)
    };

    // Calculate trending scores for each catalog item
    for (auto& item : catalog) {
        item.trendingScore = calculateTrendingScore(item.totalViews, item.userRating, item.releaseYear);
    }

    // Sort catalog items by trending score in descending order
    std::sort(catalog.begin(), catalog.end(), [](const CatalogItem& a, const CatalogItem& b) {
        return a.trendingScore > b.trendingScore;
    });

    // Output the sorted catalog by trending score
    std::cout << "Catalog Sorted by Trending Score:\n";
    for (const auto& item : catalog) {
        std::cout << "Title: " << item.title
                  << ", Total Views: " << item.totalViews
                  << ", User Rating: " << item.userRating
                  << ", Release Year: " << item.releaseYear
                  << ", Trending Score: " << item.trendingScore << "\n";
    }

    // Example user viewing history
    std::vector<std::string> userHistory = {"Popular", "Trending"};

    // Sort catalog items by relevance to the user's viewing history
    std::sort(catalog.begin(), catalog.end(), [&userHistory](const CatalogItem& a, const CatalogItem& b) {
        return calculateRelevance(a, userHistory) > calculateRelevance(b, userHistory);
    });

    // Output the sorted catalog by relevance
    std::cout << "\nCatalog Sorted by Relevance:\n";
    for (const auto& item : catalog) {
        std::cout << "Title: " << item.title
                  << ", Total Views: " << item.totalViews
                  << ", User Rating: " << item.userRating
                  << ", Release Year: " << item.releaseYear
                  << ", Trending Score: " << item.trendingScore
                  << "\n";
    }

    return 0;
}
