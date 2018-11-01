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
    int findSecondMinimumValue(TreeNode* root) {
        int secondMin = root->val;
        findSecondMinimumValueAux(root, root->val, &secondMin);
        return (secondMin==root->val ? -1:secondMin);
    }

    void findSecondMinimumValueAux(TreeNode* root, int min, int * sMin) {
        if (root == NULL) {
            return;
        }
        if (root->val > min) {
            *sMin = (*sMin==min ? root->val:std::min(*sMin, root->val));
        }
        findSecondMinimumValueAux(root->left, min, sMin);
        findSecondMinimumValueAux(root->right, min, sMin);
    }
};

int main() {

}