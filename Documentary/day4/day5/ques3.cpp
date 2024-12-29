#include <iostream>
using namespace std;

int main() {
    int n, searchNum, flag = 0;

    // Input the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    // Input the elements of the array
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input the number to be searched
    cout << "Enter the number to search: ";
    cin >> searchNum;

    // Linear search
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchNum) {
            cout << "Number found at position " << i + 1 << " (index " << i << ")." << endl;
            flag = 1;
            break;
        }
    }

    if (!flag) {
        cout << "Number not found in the array." << endl;
    }

    return 0;
}
