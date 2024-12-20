#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;

    // Input: Get the value of n
    cout << "Enter a positive integer: ";
    cin >> n;

    // Calculate the sum of natural numbers up to n
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    // Output: Display the sum
    cout << "The sum of natural numbers up to " << n << " is: " << sum << endl;

    return 0;
}
