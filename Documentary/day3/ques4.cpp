#include <iostream>
using namespace std;

// Function to find the winner using the Josephus problem approach
int findTheWinner(int n, int k) {
    int result = 0; // Base case: with 1 person, the winner is at position 0
    
    // Iteratively compute the winner position for all numbers from 2 to n
    for (int i = 2; i <= n; ++i) {
        result = (result + k) % i;
    }
    
    // Since the result is 0-indexed, we add 1 to convert it to 1-indexed
    return result + 1;
}

int main() {
    int n, k;
    
    cout << "Enter the number of friends (n): ";
    cin >> n;
    
    cout << "Enter the step count (k): ";
    cin >> k;
    
    // Find and print the winner
    cout << "The winner is friend number: " << findTheWinner(n, k) << endl;
    
    return 0;
}
