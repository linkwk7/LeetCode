#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        }
        if (t1 == NULL) {
            return t2;
        }
        if (t2 == NULL) {
            return t1;
        }
        TreeNode * l = mergeTrees(t1->left, t2->left);
        TreeNode * r = mergeTrees(t1->right, t2->right);
        t1->val += t2->val;
        t1->left = l;
        t1->right = r;
        return t1;
    }
};

int main() {

}