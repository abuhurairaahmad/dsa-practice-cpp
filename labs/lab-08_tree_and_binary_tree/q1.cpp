#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    void inorderHelper(Node* node) {
        if (node == nullptr) return;
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }

    void preorderHelper(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void postorderHelper(Node* node) {
        if (node == nullptr) return;
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << " ";
    }

    bool searchHelper(Node* node, int val) {
        if (node == nullptr) return false;
        if (node->data == val) return true;
        return searchHelper(node->left, val) || searchHelper(node->right, val);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;
                return;
            } else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = newNode;
                return;
            } else {
                q.push(current->right);
            }
        }
    }

    void inorder() {
        inorderHelper(root);
        cout << endl;
    }

    void preorder() {
        preorderHelper(root);
        cout << endl;
    }

    void postorder() {
        postorderHelper(root);
        cout << endl;
    }

    bool search(int key) {
        return searchHelper(root, key);
    }
};


int main(){
    BinaryTree tree;

    for (int i = 1; i <= 7; ++i) {
        tree.insert(i);
    }

    cout << "--- Binary Tree Traversals ---\n";
    cout << "Inorder Traversal:   ";
    tree.inorder();    // Expected: 4 2 5 1 6 3 7

    cout << "Preorder Traversal:  ";
    tree.preorder();   // Expected: 1 2 4 5 3 6 7

    cout << "Postorder Traversal: ";
    tree.postorder();  // Expected: 4 5 2 6 7 3 1

    cout << "\n--- Search Operations ---\n";
    cout << std::boolalpha;
    cout << "Search for 5:  " << tree.search(5) << " (Expected: true)\n";
    cout << "Search for 10: " << tree.search(10) << " (Expected: false)\n";
    
    return 0;
}
