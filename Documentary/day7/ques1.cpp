#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }

private:
    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (!node) return; // Base case: if the node is null, return
        inorderHelper(node->left, result);   // Traverse left subtree
        result.push_back(node->val);         // Visit the root node
        inorderHelper(node->right, result);  // Traverse right subtree
    }
};

// Example usage
int main() {
    // Construct the binary tree: [1, null, 2, 3]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Solution instance
    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    // Print the result
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (if necessary)
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
