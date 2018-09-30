#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTAux(root, nullptr, nullptr);
    }

    bool isValidBSTAux(TreeNode * root, int * min, int * max) {
        if (root == NULL) {
            return true;
        }

        if ((min != nullptr && root->val<*min)||(max != nullptr && root->val>*max)) {
            return false;
        }
        return isValidBSTAux(root->left, min, &(root->val)) && isValidBSTAux(root->right, &(root->val), max);
    }
};

int main() {

}