#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void findClosestSumPair(vector<int>& arr) {
    int n = arr.size();
    if (n < 2) {
        cout << "Array must have at least two elements!" << endl;
        return;
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    int closestSum = INT_MAX;
    int pair1 = 0, pair2 = 0;

    // Use two pointers to find the closest sum to zero
    while (left < right) {
        int sum = arr[left] + arr[right];

        // Update the closest sum and the pair
        if (abs(sum) < abs(closestSum)) {
            closestSum = sum;
            pair1 = arr[left];
            pair2 = arr[right];
        }

        // Adjust pointers based on the sum
        if (sum < 0) {
            left++; // Move left pointer to increase sum
        } else {
            right--; // Move right pointer to decrease sum
        }
    }

    cout << "The pair whose sum is closest to zero: " << pair1 << " and " << pair2 << endl;
    cout << "Their sum: " << closestSum << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findClosestSumPair(arr);

    return 0;
}
