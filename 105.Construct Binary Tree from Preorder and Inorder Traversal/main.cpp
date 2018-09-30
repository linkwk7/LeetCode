#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeAux(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

    TreeNode* buildTreeAux(std::vector<int>::iterator preBegin, std::vector<int>::iterator preEnd,\
        std::vector<int>::iterator inBegin, std::vector<int>::iterator inEnd) {
        if (preEnd-preBegin == 0) {
            return NULL;
        } else if (preEnd-preBegin==1) {
            return new TreeNode(*preBegin);
        }

        TreeNode * root = new TreeNode(*preBegin);
        auto iter = std::find(inBegin, inEnd, root->val);
        int leftSize = iter-inBegin;
        root->left = buildTreeAux(preBegin+1, preBegin+leftSize+1, inBegin, inBegin+leftSize);
        root->right = buildTreeAux(preBegin+leftSize+1, preEnd, inBegin+leftSize+1, inEnd);

        return root;
    }
};

int main() {
    return 0;
}