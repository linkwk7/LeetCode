#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * tail = NULL;
        ListNode * head = NULL;
        for (; l1!=NULL && l2!=NULL; ) {
            ListNode* & current = (l1->val < l2->val ? l1:l2);
            if (tail == NULL) {
                head = current;
            } else {
                tail->next = current;
            }
            tail = current;
            current = current->next;
        }

        ListNode * current = (l1==NULL ? l2:l1);
        if (current != NULL) {
            if (tail == NULL) {
                head = current;
            } else {
                tail->next = current;
            }
        }

        return head;
    }
};

int main() {

}
