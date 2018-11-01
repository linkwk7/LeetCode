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
        if (root == NULL) {
            return NULL;
        }

        int min = std::min(p->val, q->val);
        int max = std::max(p->val, q->val);
        if (root->val < min) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (root->val > max) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};

int main() {

}