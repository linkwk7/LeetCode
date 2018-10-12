#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != NULL) {
            TreeNode * left = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(left);
        }

        return root;
    }
};

int main() {
    return 0;
}