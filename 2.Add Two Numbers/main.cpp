#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = nullptr;
        ListNode * last = nullptr;
        int carry = 0;
        for (; l1!=NULL || l2!=NULL;) {
            int l1val = (l1==NULL ? 0: l1->val);
            int l2val = (l2==NULL ? 0: l2->val);

            int sum = l1val+l2val+carry;
            carry = sum/10;
            if (head == nullptr) {
                head = new ListNode(sum%10);
                last = head;
            } else {
                last->next = new ListNode(sum%10);
                last = last->next;
            }

            l1 = (l1==NULL? NULL: l1->next);
            l2 = (l2==NULL? NULL: l2->next);
        }
        if (carry != 0) {
            last->next = new ListNode(carry);
        }
        return head;
    }
};

int main() {
    return 0;
}