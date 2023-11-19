#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode *buildTree(vector<int> inOrder, vector<int> backOrder) {
    if (inOrder.size() == 0) {
        return nullptr;
    }
    int root_val = backOrder[backOrder.size() - 1];
    TreeNode *root = new TreeNode(root_val);
    for (int i = 0; i < inOrder.size(); i++) {
        if (inOrder[i] == root_val) {
            vector<int> inLeft(inOrder.begin(), inOrder.begin() + i);
            vector<int> backLeft(backOrder.begin(), backOrder.begin() + i);
            root->left = buildTree(inLeft, backLeft);
            vector<int> inRight(inOrder.begin() + i + 1, inOrder.end());
            vector<int> backRight(backOrder.begin() + i, backOrder.end() - 1);
            root->right = buildTree(inRight, backRight);
            break;
        }
    }
    return root;
}

void prePrint(TreeNode *root) {
    if (root == nullptr) {
        return ;
    }
    cout << root->val << " ";
    prePrint(root->left);
    prePrint(root->right);
}
int main() {
    vector<int> inOrder = {4, 2, 5, 1, 6, 3};
    vector<int> backOrder = {4, 5, 2, 6, 3, 1};
    TreeNode* root = buildTree(inOrder, backOrder);
    prePrint(root);
    cout << endl;
}

