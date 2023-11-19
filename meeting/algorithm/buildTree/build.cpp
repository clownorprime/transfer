#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class TreeNode {
    public:
        char val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

TreeNode *buildTree(const string& s) {
    TreeNode *root = nullptr;
    TreeNode *current = nullptr;
    stack<TreeNode*> mystack;
    int flag = 0; // 1代表左子树，2代表右子树
    for (auto c : s) {
        switch(c) {
            case '(': 
                flag = 1;
                mystack.push(current);
                break;
            case ',':
                flag = 2;
                break;
            case ')':
                mystack.pop();
                break;
            default:
                current = new TreeNode(c);
                if (root == nullptr) {
                    root = current;
                } else if (flag == 1) {
                    mystack.top()->left = current;
                } else if (flag == 2) {
                    mystack.top()->right = current;
                }
                flag = 0;
        }
    }
    return root;
}

void inOrder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void preOrder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void backOrder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    backOrder(root->left);
    backOrder(root->right);
    cout << root->val << " ";
}

void iterPreOrder(TreeNode *root) 
{
    if (root == nullptr) {
        return;
    }
    stack<TreeNode*> mystack;
    mystack.push(root);
    cout << root->val << " ";
    while(!mystack.empty()) {
        TreeNode *tmp = mystack.top();
        while(tmp->left) {
            mystack.push(tmp->left);
            cout << tmp->left->val << " ";
            tmp = tmp->left;
        }
        while(!mystack.empty() && mystack.top()->right == nullptr) {
            mystack.pop();
        }
        if (mystack.empty()) {
            return;
        }
        tmp = mystack.top()->right;
        mystack.pop();
        cout << tmp->val << " ";
        mystack.push(tmp);
    }
}

void iterInOrder(TreeNode *root) {
    if (root == nullptr)  {
        return ;
    }
    stack<TreeNode*> mystack;
    mystack.push(root);
    while(!mystack.empty()) {
        TreeNode *tmp = mystack.top();
        while(tmp->left) {
            mystack.push(tmp->left);
            tmp = tmp->left;
        }
        while(!mystack.empty() && mystack.top()->right == nullptr) {
            cout << mystack.top()->val << " ";
            mystack.pop();
        }
        if (mystack.empty()) {
            return;
        }
        tmp = mystack.top()->right;
        cout << mystack.top()->val << " ";
        mystack.pop();
        mystack.push(tmp);
    }
}

void iterBackOrder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    vector<char> ans;
    stack<TreeNode*> mystack;
    mystack.push(root);
    ans.push_back(root->val);
    while(!mystack.empty()) {
        TreeNode *tmp = mystack.top();
        while(tmp->right) {
            ans.push_back(tmp->right->val);
            mystack.push(tmp->right);
            tmp = tmp->right;
        }
        while(!mystack.empty() && mystack.top()->left == nullptr) {
            mystack.pop();
        }
        if (mystack.empty()) {
            break;
        }
        tmp = mystack.top()->left;
        mystack.pop();
        ans.push_back(tmp->val);
        mystack.push(tmp);
    }
    for (auto itr = ans.rbegin(); itr < ans.rend(); itr++) {
        cout << *itr << " ";
    }
}

int main() {
    string input = "1(2(3,4),5(6,7))";
    TreeNode *root = buildTree(input);
    cout << "preOrder: ";
    preOrder(root);
    cout << endl;
    cout << "inOrder: ";
    inOrder(root);
    cout << endl;
    cout << "backOrder: ";
    backOrder(root);
    cout << endl;
    cout << "iterPreOrder: ";
    iterPreOrder(root);
    cout << endl;
    cout << "iterInorder: ";
    iterInOrder(root);
    cout << endl;
    cout << "iterBackOrder: ";
    iterBackOrder(root);
    cout << endl;
}
