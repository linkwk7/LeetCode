#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        std::queue<TreeNode*> que;
        que.push(root);

        TreeNode * left = NULL;
        for (; !que.empty(); ) {
            int size = que.size();
            left = que.front();
            for (int i=0; i<size; i++) {
                TreeNode * current = que.front();
                if (current!=NULL) {
                    if (current->left != NULL) {
                        que.push(current->left);
                    }
                    if (current->right != NULL) {
                        que.push(current->right);
                    }
                }
                que.pop();
            }
        }
        return left->val;
    }
};

int main() {

}