#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        int robRoot = 0;
        int notRobRoot = 0;
        robAux(root, &robRoot, &notRobRoot);
        return std::max(robRoot, notRobRoot);
    }

    void robAux(TreeNode* root, int * robRoot, int * notRobRoot) {
        if (root == NULL) {
            *robRoot = 0;
            *notRobRoot = 0;
            return;
        }

        int lRobRoot = 0;
        int lNotRobRoot = 0;
        robAux(root->left, &lRobRoot, &lNotRobRoot);
        int rRobRoot = 0;
        int rNotRobRoot = 0;
        robAux(root->right, &rRobRoot, &rNotRobRoot);
        *robRoot = root->val+lNotRobRoot+rNotRobRoot;
        *notRobRoot = std::max(lRobRoot, lNotRobRoot) + std::max(rRobRoot, rNotRobRoot);
    }
};

int main() {

}