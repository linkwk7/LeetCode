#include <iostream>
#include <vector>
#include <queue>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;

        if (root == NULL) {
            return result;
        }

        std::queue<TreeNode *> level;
        level.push(root);

        for (; !level.empty(); ) {
            result.push_back(std::vector<int>());
            for (int i=0, sz=level.size(); i<sz; i++) {
                result.back().push_back(level.front()->val);
                if (level.front()->left != NULL) {
                    level.push(level.front()->left);
                }
                if (level.front()->right != NULL) {
                    level.push(level.front()->right);
                }
                level.pop();
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
