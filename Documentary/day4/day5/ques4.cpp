#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int searchNum) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == searchNum) {
            return mid; // Number found
        } else if (arr[mid] < searchNum) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Number not found
}

int main() {
    int n, searchNum;

    // Input the size of the array
    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    int arr[n];

    // Input the elements of the sorted array
    cout << "Enter " << n << " elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input the number to be searched
    cout << "Enter the number to search: ";
    cin >> searchNum;

    // Perform binary search
    int result = binarySearch(arr, n, searchNum);

    if (result != -1) {
        cout << "Number found at position " << result + 1 << " (index " << result << ")." << endl;
    } else {
        cout << "Number not found in the array." << endl;
    }

    return 0;
}
