#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeAux(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }

    TreeNode* buildTreeAux(std::vector<int>::iterator inBegin, std::vector<int>::iterator inEnd, \
        std::vector<int>::iterator postBegin, std::vector<int>::iterator postEnd) {
        if (inEnd - inBegin == 0) {
            return NULL;
        } else if (inEnd - inBegin == 1) {
            return new TreeNode(*inBegin);
        }

        TreeNode * root = new TreeNode(*(postEnd-1));
        auto iter = std::find(inBegin, inEnd, root->val);
        int rightSize = inEnd-iter-1;
        root->left = buildTreeAux(inBegin, iter, postBegin, postEnd-rightSize-1);
        root->right = buildTreeAux(iter+1, inEnd, postEnd-rightSize-1, postEnd-1);

        return root;
    }
};

int main() {
    return 0;
}