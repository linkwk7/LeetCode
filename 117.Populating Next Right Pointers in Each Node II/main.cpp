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
        TreeLinkNode * head = root;
        for (; head != NULL; ) {
            TreeLinkNode * current = head;
            head = NULL;

            TreeLinkNode * prev = NULL;
            for (; current!=NULL; current=current->next) {
                if (current->left != NULL) {
                    if (head == NULL) {
                        head = current->left;
                    }
                    if (prev == NULL) {
                        prev = current->left;
                    } else {
                        prev->next = current->left;
                        prev = current->left;
                    }
                }
                if (current->right != NULL) {
                    if (head == NULL) {
                        head = current->right;
                    }
                    if (prev == NULL) {
                        prev = current->right;
                    } else {
                        prev->next = current->right;
                        prev = current->right;
                    }
                }
            }
        }
    }
};

int main() {
    return 0;
}