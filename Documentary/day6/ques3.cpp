#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

// Function to find the k-th smallest sum of a matrix with the shortest row
int kthSmallestSum(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(); // Number of rows
    if (m == 0 || matrix[0].size() == 0) return -1;

    int n = matrix[0].size(); // Length of the shortest row

    // Min-heap to store sums and their indices
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> minHeap;

    // Initialize heap with the first column's elements
    vector<int> indices(m, 0); // Indices in each row
    int initialSum = 0;
    for (int i = 0; i < m; i++) {
        initialSum += matrix[i][0]; // Add the first elements of each row
    }
    minHeap.push({initialSum, indices}); // Push initial sum with indices

    // Extract k smallest sums
    while (k--) {
        auto [currentSum, currentIndices] = minHeap.top();
        minHeap.pop();

        if (k == 0) return currentSum; // Return the k-th smallest sum

        // Generate the next sums by incrementing each row's index
        for (int i = 0; i < m; i++) {
            if (currentIndices[i] + 1 < n) { // Check bounds
                vector<int> newIndices = currentIndices;
                newIndices[i]++;
                int newSum = currentSum - matrix[i][currentIndices[i]] + matrix[i][newIndices[i]];
                minHeap.push({newSum, newIndices});
            }
        }
    }

    return -1; // If k is out of range
}

int main() {
    int rows, cols, k;
    cout << "Enter the number of rows and columns in the matrix: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the elements of the matrix (row-wise sorted):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = kthSmallestSum(matrix, k);
    if (result != -1) {
        cout << "The k-th smallest sum is: " << result << endl;
    } else {
        cout << "Invalid value of k!" << endl;
    }

    return 0;
}
