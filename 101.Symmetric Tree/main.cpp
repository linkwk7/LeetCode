#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root==NULL || isSymmetricAux(root->left,root->right);
    }

    bool isSymmetricAux(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL) {
            return left==right;
        }
        if (left->val != right->val) {
            return false;
        }
        return isSymmetricAux(left->left, right->right) && isSymmetricAux(left->right, right->left);
    }
};

int main() {

}