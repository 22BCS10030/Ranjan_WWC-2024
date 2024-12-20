#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false; // Numbers <= 1 are not prime
    for (int i = 2; i * i <= num; i++) { // Check divisors up to sqrt(num)
        if (num % i == 0) {
            return false; // Not prime if divisible by i
        }
    }
    return true; // Prime if no divisors found
}

int main() {
    int n;

    // Input: Get the number to check
    cout << "Enter a number: ";
    cin >> n;

    // Check if the number is prime
    if (isPrime(n)) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}
