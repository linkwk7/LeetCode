#include <iosteram>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
            return false;
        }
        return isSubtreeAux(s, t) || (isSubtree(s->left, t) || isSubtree(s->right, t));
    }

    bool isSubtreeAux(TreeNode* s, TreeNode* t) {
        if (s == NULL || t == NULL) {
            return s == t;
        }
        if (s->val != t->val) {
            return false;
        }
        return isSubtreeAux(s->left, t->left) && isSubtreeAux(s->right, t->right);
    }
};

int main() {

}