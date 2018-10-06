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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;

        pathSumAux(result, path, root, 0, sum);

        return result;
    }

    void pathSumAux(std::vector<std::vector<int>> & result, std::vector<int> & path, TreeNode * current, int currentSum, int sum) {
        if (current == NULL) {
            return;
        }
        
        path.push_back(current->val);
        currentSum += current->val;
        if (currentSum == sum) {
            if (current->left == NULL && current->right == NULL) {
                result.push_back(path);
            } else {
                pathSumAux(result, path, current->left, currentSum, sum);
                pathSumAux(result, path, current->right, currentSum, sum);
            }
        } else {
            pathSumAux(result, path, current->left, currentSum, sum);
            pathSumAux(result, path, current->right, currentSum, sum);
        }
        currentSum -= current->val;
        path.pop_back();
    }
};

int main() {
    return 0;
}