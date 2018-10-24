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
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        diameterOfBinaryTreeAux(root, &max);
        return max;
    }

    int diameterOfBinaryTreeAux(TreeNode* root, int * max) {
        if (root == NULL) {
            return 0;
        }
        int leftDep = diameterOfBinaryTreeAux(root->left, max);
        int rightDep = diameterOfBinaryTreeAux(root->right, max);
        if (leftDep + rightDep > *max) {
            *max = leftDep + rightDep;
        }
        return std::max(leftDep, rightDep)+1;
    }
};

int main() {

}