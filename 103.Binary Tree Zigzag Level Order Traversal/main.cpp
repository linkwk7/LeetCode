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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;

        if (root == NULL) {
            return result;
        }

        int depth = 0;
        std::vector<TreeNode *> lastLevel;
        std::vector<TreeNode *> nextLevel;

        lastLevel.push_back(root);

        for (; !lastLevel.empty(); ) {
            result.push_back(std::vector<int>());

            for (int i=0; i<lastLevel.size(); i++) {
                if (lastLevel[i]->left != NULL) {
                    nextLevel.push_back(lastLevel[i]->left);
                }
                if (lastLevel[i]->right != NULL) {
                    nextLevel.push_back(lastLevel[i]->right);
                }
            }

            if (depth%2 == 0) {
                for (int i=0; i<lastLevel.size(); i++) {
                    result[depth].push_back(lastLevel[i]->val);
                }
            } else {
                for (int i=lastLevel.size()-1; i>=0; i--) {
                    result[depth].push_back(lastLevel[i]->val);
                }
            }
            
            lastLevel = nextLevel;
            nextLevel.clear();
            depth++;
        }

        return result;
    }
};

int main() {
    return 0;
}