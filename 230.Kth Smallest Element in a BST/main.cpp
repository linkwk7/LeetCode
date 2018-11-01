#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) {
            return -1;
        }

        int leftCount = kthSmallestAux(root->left);
        if (leftCount+1 > k) {
            return kthSmallest(root->left, k);
        } else if (leftCount+1 == k) {
            return root->val;
        }
        return kthSmallest(root->right, k-leftCount-1);
    }

    int kthSmallestAux(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return kthSmallestAux(root->left)+kthSmallestAux(root->right)+1;
    }
};

int main() {

}