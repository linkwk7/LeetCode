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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;

        std::stack<TreeNode*> path;
        TreeNode * current = root;
        TreeNode * last = NULL;
        for (; current!=NULL; current = current->left) {
            path.push(current);
        }

        for (; !path.empty(); ) {
            current = path.top();
            path.pop();

            if (current->right == NULL || current->right == last) {
                result.push_back(current->val);
                last = current;
            } else {
                path.push(current);
                current = current->right;
                for (; current!=NULL; current=current->left) {
                    path.push(current);
                }
            }
        }
        return result;
    }
};

int main() {

}