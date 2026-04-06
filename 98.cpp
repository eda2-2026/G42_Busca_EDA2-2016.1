#include <iostream>
#include <climits>
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
 
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};
 
class Solution {
public:
    bool check(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr) {
            return true;
        }
 
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }
 
        return check(root->left, minVal, root->val) &&
               check(root->right, root->val, maxVal);
    }
 
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
 
int main() {
    /*
            2
           / \
          1   3
    */
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
 
    Solution sol;
 
    if (sol.isValidBST(root)) {
        cout << "A arvore e uma BST valida" << endl;
    } else {
        cout << "A arvore nao e uma BST valida" << endl;
    }
 
    return 0;
}