#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // If the array is empty, return 0.

        int j = 1; // Pointer to place the next unique element

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) { // If current element is different from the previous one
                nums[j] = nums[i];         // Place it at the next unique position
                ++j;                       // Increment the unique element counter
            }
        }

        return j; // j is the count of unique elements
    }
};

int main() {
    vector<int> nums = {1, 1, 2}; // Example input
    Solution sol;
    int length = sol.removeDuplicates(nums);
    
    cout << "Number of unique elements: " << length << endl;
    cout << "Modified array: ";
    
    // Print the modified array with unique elements
    for (int i = 0; i < length; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}
