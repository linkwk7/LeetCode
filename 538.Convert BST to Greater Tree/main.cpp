#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        convertBSTAux(root, 0);
        return root;
    }

    int convertBSTAux(TreeNode* root, int add) {
        if (root == NULL) {
            return add;
        }
        int sum = convertBSTAux(root->right, add);
        root->val += sum;
        sum = convertBSTAux(root->left, root->val);
        return sum;
    }
};

int main() {

}