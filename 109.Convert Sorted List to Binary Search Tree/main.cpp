#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBSTAux(head, NULL);
    }

    TreeNode* sortedListToBSTAux(ListNode* head, ListNode* end) {
        if (head == end) {
            return NULL;
        }

        ListNode * mid = midOfList(head, end);
        TreeNode * root = new TreeNode(mid->val);
        root->left = sortedListToBSTAux(head, mid);
        root->right = sortedListToBSTAux(mid->next, end);
        return root;
    }

    ListNode* midOfList(ListNode* head, ListNode* end) {
        ListNode * slow = head;
        ListNode * fast = head;

        for (; fast!=end; ) {
            fast = fast->next;
            if (fast == end) {
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {

}