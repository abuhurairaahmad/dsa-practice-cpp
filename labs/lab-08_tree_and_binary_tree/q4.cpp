#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    unordered_map<int, int> inorderIndexMap;
    int preorderIndex = 0;

    TreeNode* buildSubtree(const vector<int>& preorder, int inStart, int inEnd) {
        // There is nothing to build for an empty range.
        if (inStart > inEnd) {
            return nullptr;
        }

        // Preorder gives us the next root.
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Use inorder to split the values into left and right parts.
        int rootIndexInorder = inorderIndexMap[rootVal];

        // Build the left side first, followed by the right side.
        root->left = buildSubtree(preorder, inStart, rootIndexInorder - 1);
        root->right = buildSubtree(preorder, rootIndexInorder + 1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        preorderIndex = 0;
        inorderIndexMap.clear();

        // Save each value's position so we can find it quickly.
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        return buildSubtree(preorder, 0, inorder.size() - 1);
    }
};

// Prints the tree one level at a time.
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "[]\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    cout << "[";
    bool first = true;
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr != nullptr) {
            if (!first) cout << ", ";
            cout << curr->val;
            first = false;
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    cout << "]\n";
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution builder;
    TreeNode* root = builder.buildTree(preorder, inorder);

    cout << "Constructed Tree (Level-Order): ";
    printLevelOrder(root);

    return 0;
}