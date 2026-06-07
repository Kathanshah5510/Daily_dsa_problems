#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main() {
    vector<vector<int>> descriptions = {{1, 2, 1}, {2, 3, 0}, {3, 4, 1}};
    unordered_map<int, TreeNode*> nodes;
    unordered_set<int> children;

    for (const auto& desc : descriptions) {
        int parent = desc[0], child = desc[1], isLeft = desc[2];
        if (nodes.find(parent) == nodes.end()) {
            nodes[parent] = new TreeNode(parent);
        }
        if (nodes.find(child) == nodes.end()) {
            nodes[child] = new TreeNode(child);
        }
        if (isLeft) {
            nodes[parent]->left = nodes[child];
        } else {
            nodes[parent]->right = nodes[child];
        }
        children.insert(child);
    }

    TreeNode* root = nullptr;
    for (const auto& [key, node] : nodes) {
        if (children.find(key) == children.end()) {
            root = node;
            break;
        }
    }

    // print the answer
    function<void(TreeNode*)> printTree = [&](TreeNode* node) {
        if (!node) return;
        cout << node->val << " ";
        printTree(node->left);
        printTree(node->right);
    };
    printTree(root);

    // The variable 'root' now points to the root of the constructed binary tree.
    return 0;
}