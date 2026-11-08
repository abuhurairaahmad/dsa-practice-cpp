#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

// A simple node for the binary tree.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // Returns the best result for both choices at this node:
    // first means rob it, and second means leave it.
    pair<int, int> robHelper(TreeNode* root) {
        // An empty tree does not add anything.
        if (root == nullptr) {
            return {0, 0};
        }

        // Get the answers from both subtrees before deciding for this node.
        pair<int, int> left = robHelper(root->left);
        pair<int, int> right = robHelper(root->right);

        // If we rob this house, its children cannot be robbed.
        int robCurrent = root->val + left.second + right.second;

        // Otherwise, take whichever option gives more money for each child.
        int notRobCurrent = max(left.first, left.second) + 
                            max(right.first, right.second);

        return {robCurrent, notRobCurrent};
    }

public:
    int rob(TreeNode* root) {
        pair<int, int> result = robHelper(root);
        return max(result.first, result.second);
    }
};

int main() {
    Solution solver;

    // First example tree.
    //         3
    //       /   \
    //      2     3
    //       \     \
    //        3     1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(3);
    root1->right->right = new TreeNode(1);

    cout << "Example 1 Max Money: " << solver.rob(root1) 
              << " (Expected: 7)\n";

    // Second example tree.
    //         3
    //       /   \
    //      4     5
    //     / \     \
    //    1   3     1
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(1);

    cout << "Example 2 Max Money: " << solver.rob(root2) 
              << " (Expected: 9)\n";

    return 0;
}