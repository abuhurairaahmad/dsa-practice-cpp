#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int checkHeight(TreeNode* node) {
    if (!node) return 0;

    int leftHeight = checkHeight(node->left);
    if (leftHeight == -1) return -1; // Left subtree is not balanced

    int rightHeight = checkHeight(node->right);
    if (rightHeight == -1) return -1; // Right subtree is not balanced

    if (abs(leftHeight - rightHeight) > 1) return -1; // Current node is not balanced

    return max(leftHeight, rightHeight) + 1; // Return height of the current node
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

int main(){
    cout << boolalpha;
    // I am taking example 1.
    //         3
    //       /   \
    //      9     20
    //           /  \
    //          15   7
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    cout << "Example 1 is balanced: " 
              << isBalanced(root1) << " (Expected: true)\n";

    // I am taking example 2.
    //             1
    //           /   \
    //          2     2
    //        /   \
    //       3     3
    //      / \
    //     4   4
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->left->left->right = new TreeNode(4);

    cout << "Example 2 is balanced: " 
              << isBalanced(root2) << " (Expected: false)\n";
    
    return 0;
}
