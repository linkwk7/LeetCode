#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max = root->val;
        if (root->left != NULL) {
            max = std::max(max, maxPathSum(root->left));
        }
        if (root->right != NULL) {
            max = std::max(max, maxPathSum(root->right));
        }
        max = std::max(max, maxPathSumAux(root->left)+maxPathSumAux(root->right)+root->val);
        return max;
    }

    int maxPathSumAux(TreeNode * root) {
        if (root == NULL) {
            return 0;
        }
        return std::max(std::max({maxPathSumAux(root->left), maxPathSumAux(root->right), 0})+root->val, 0);
    }
};

int main() {

}