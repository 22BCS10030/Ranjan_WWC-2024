#include <iostream>
#include <cmath>
const int MOD = 1e9 + 7;

int minimumNonZeroProduct(int p) {
    // Calculate 2^p - 1 (the largest number in the range)
    long long maxNum = (1LL << p) - 1;
    
    // Calculate the minimum non-zero product modulo MOD
    long long minProduct = maxNum * (maxNum - 1) % MOD;
    
    return minProduct;
}

int main() {
    int p;
    std::cout << "Enter the value of p: ";
    std::cin >> p;
    
    std::cout << "The minimum non-zero product is: " << minimumNonZeroProduct(p) << std::endl;
    
    return 0;
}
