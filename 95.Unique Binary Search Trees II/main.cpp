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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return std::vector<TreeNode*>();
        }
        
        return generateTreesRange(1, n+1);
    }

    std::vector<TreeNode*> generateTreesRange(int first, int last) {
        std::vector<TreeNode*> result;

        if (last == first) {
            result.push_back(NULL);
            return result;
        } else if (last-first == 1) {
            result.push_back(new TreeNode(first));
            return result;
        }

        for (int i=first; i<last; i++) {
            std::vector<TreeNode*> left = generateTreesRange(first, i);
            std::vector<TreeNode*> right = generateTreesRange(i+1, last);

            for (int li=0,lsz=left.size(); li<lsz; li++) {
                for (int ri=0,rsz=right.size(); ri<rsz; ri++) {
                    TreeNode * root = new TreeNode(i);
                    root->left = left[li];
                    root->right = right[ri];
                    result.push_back(root);
                }
            }
        }

        return result;
    }
};

int main() {

}
