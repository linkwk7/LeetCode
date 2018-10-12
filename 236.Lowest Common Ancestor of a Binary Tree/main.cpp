#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lowestCommonAncestorAux(root, p, q);
    }

    TreeNode* lowestCommonAncestorAux(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == NULL) {
            return root;
        }

        TreeNode* left = lowestCommonAncestorAux(root->left, p, q);
        TreeNode* right = lowestCommonAncestorAux(root->right, p, q);
        if (left != NULL && right != NULL) {
            return root;
        }
        if (left != NULL) {
            return left;
        }
        return right;
    }
};

int main() {
    return 0;
}