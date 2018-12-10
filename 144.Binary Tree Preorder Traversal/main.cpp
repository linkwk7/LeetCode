#include <iostream>
#include <vector>
#include <stack>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;

        std::stack<TreeNode*> path;
        TreeNode * current = root;
        for (; current!=NULL || !path.empty(); ) {
            for (; current!=NULL; current=current->left) {
                result.push_back(current->val);
                path.push(current);
            }

            current = path.top();
            path.pop();
            current = current->right;
        }
        return result;
    }
};

int main() {

}