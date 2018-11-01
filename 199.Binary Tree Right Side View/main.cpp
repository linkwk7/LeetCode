#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;

        if (root == NULL) {
            return result;
        }

        std::queue<TreeNode*> que;
        que.push(root);

        for (; !que.empty(); ) {
            int count = que.size();
            for (int i=0; i<count; i++) {
                if (i == count-1) {
                    result.push_back(que.front()->val);
                }
                TreeNode * current = que.front();
                if (current != NULL) {
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
        return result;
    }
};

int main() {

}