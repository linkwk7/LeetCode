#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        return pathSumAux(root, sum)+pathSum(root->left, sum)+pathSum(root->right, sum);
    }

    int pathSumAux(TreeNode* root, int target) {
        if (root == NULL) {
            return 0;
        }
        return (root->val==target ? 1:0)+pathSumAux(root->left, target-root->val)+pathSumAux(root->right, target-root->val);
    }
};

int main() {

}