#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        flattenTreeAux(root);
    }

    TreeNode * flattenTreeAux(TreeNode * root) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode * lchdTail = flattenTreeAux(root->left);
        TreeNode * rchdTail = flattenTreeAux(root->right);

        if (lchdTail == NULL && rchdTail == NULL) {
            return root;
        } else if (lchdTail == NULL) {
            root->left = NULL;
            return rchdTail;
        } else if (rchdTail == NULL) {
            root->right = root->left;
            root->left = NULL;
            return lchdTail;
        }

        lchdTail->left = NULL;
        lchdTail->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return rchdTail;
    }
};

int main() {
    return 0;
}