#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;

        std::stack<TreeNode*> stk;
        for (; root != NULL || !stk.empty(); ) {
            for (; root!=NULL; ) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
};

int main() {

}