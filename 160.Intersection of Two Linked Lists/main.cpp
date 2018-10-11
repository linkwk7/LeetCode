#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        for (ListNode *current=headA; current!=NULL; current=current->next) {
            lenA++;
        }
        for (ListNode *current=headB; current!=NULL; current=current->next) {
            lenB++;
        }

        if (lenA < lenB) {
            for (int i=0,l=lenB-lenA; i<l; i++) {
                headB = headB->next;
            }
        } else {
            for (int i=0,l=lenA-lenB; i<l; i++) {
                headA = headA->next;
            }
        }

        for (; headA!=NULL; ) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

int main() {
    return 0;
}