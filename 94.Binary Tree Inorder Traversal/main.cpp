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

        TreeNode * current = root;
        std::stack<TreeNode *> path;
        for (; true;) {
            for (; current!=NULL; current=current->left) {
                path.push_back(current);
            }

            if (path.empty()) {
                break;
            }

            current = path.top();
            path.pop();
            result.push_back(current->val);
            current = current->right;
        }

        return result;
    }
};

int main() {

}