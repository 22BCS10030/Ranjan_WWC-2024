#include <iostream>
using namespace std;

// Define the structure of a node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function for postorder traversal
void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    // Recursively traverse the left subtree
    postorder(root->left);
    // Recursively traverse the right subtree
    postorder(root->right);
    // Visit the current node
    cout << root->data << " ";
}

// Main function
int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter the number of elements to insert in the BST: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
