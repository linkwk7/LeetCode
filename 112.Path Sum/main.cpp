#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        return hasPathSumAux(root, 0, sum);
    }

    bool hasPathSumAux(TreeNode* root, int current, int sum) {
        if (root->left == NULL && root->right == NULL) {
            return current+root->val == sum;
        }
        if (root->left != NULL && hasPathSumAux(root->left, current+root->val, sum)) {
            return true;
        }
        if (root->right != NULL && hasPathSumAux(root->right, current+root->val, sum)) {
            return true;
        }
        return false;
    }
};

int main() {

}