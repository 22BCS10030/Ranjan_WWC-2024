#include <iostream>
 {"conversationId":"e81a377b-5d40-4ee1-9ab1-8a0579f4a8cd","source":"instruct"}
using namespace std;

int lastRemaining(int n) {
    int start = 1;
    int step = 1;
    int remaining = n;
    bool left = true;
    
    while (remaining > 1) {
        if (left || remaining % 2 == 1) {
            start += step;
        }
        step *= 2;
        remaining /= 2;
        left = !left;
    }
    
    return start;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    cout << "The last remaining number is: " << lastRemaining(n) << endl;
    return 0;
}
