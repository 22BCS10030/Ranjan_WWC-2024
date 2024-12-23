#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    
    // Create a DP table where dp[i][j] represents the maximum score difference
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Base case: when the subarray has only one element, the score difference is that element
    for (int i = 0; i < n; ++i) {
        dp[i][i] = nums[i];
    }

    // Fill the DP table for larger subarrays
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
        }
    }

    // If the score difference for the whole array is non-negative, Player 1 can win or tie
    return dp[0][n-1] >= 0;
}

int main() {
    vector<int> nums = {1, 5, 2};
    
    if (PredictTheWinner(nums)) {
        cout << "Player 1 can win!" << endl;
    } else {
        cout << "Player 2 can win!" << endl;
    }
    
    return 0;
}
