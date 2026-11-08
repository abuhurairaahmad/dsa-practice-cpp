#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

int main(){
    cout << boolalpha; 
    // I am taking example 1.
    //         1
    //       /   \
    //      2     2
    //     / \   / \
    //    3   4 4   3
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    cout << "Example 1 is symmetric: " << isSymmetric(root1) << " (Expected: true)\n";
    
    // I am taking exaple 2.
    //         1
    //       /   \
    //      2     2
    //       \     \
    //        3     3
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(3);

    cout << "Example 2 is symmetric: " << isSymmetric(root2) << " (Expected: false)\n";
    
    return 0;
}
