#include <iostream>
#include <vector>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL || root->left == NULL) {
            return;
        }

        TreeLinkNode * left = root->left;
        TreeLinkNode * right = root->right;

        for (; left != NULL; ) {
            left->next = right;
            left = left->right;
            right = right->left;
        }

        connect(root->left);
        connect(root->right);
    }
};

int main() {
    return 0;
}