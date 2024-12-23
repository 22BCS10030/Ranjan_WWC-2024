#include <iostream>
#include <vector> // Include vector header
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // Placeholder for the result list
        ListNode* current = dummyHead; // Pointer to traverse the result list
        int carry = 0; // To keep track of the carry value

        // Traverse both lists until the end
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with the carry

            if (l1 != nullptr) {
                sum += l1->val; // Add value from l1
                l1 = l1->next; // Move to the next node in l1
            }

            if (l2 != nullptr) {
                sum += l2->val; // Add value from l2
                l2 = l2->next; // Move to the next node in l2
            }

            carry = sum / 10; // Update the carry
            current->next = new ListNode(sum % 10); // Create a new node for the digit
            current = current->next; // Move to the next node in the result list
        }

        return dummyHead->next; // Return the result list, skipping the dummy head
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& nums) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* current = dummyHead;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummyHead->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Example input: 342 (represented as 2 -> 4 -> 3) and 465 (represented as 5 -> 6 -> 4)
    vector<int> nums1 = {2, 4, 3};
    vector<int> nums2 = {5, 6, 4};

    ListNode* l1 = createList(nums1);
    ListNode* l2 = createList(nums2);

    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result); // Print the resulting linked list

    return 0;
}
