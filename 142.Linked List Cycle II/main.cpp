#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;

        int total = 0;
        bool contain = false;
        for (; slow != NULL && fast != NULL; ) {
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL) {
                return NULL;
            }
            fast = fast->next;
            total++;

            if (slow == fast) {
                contain = true;
                break;
            }
        }
        if (!contain) {
            return NULL;
        }

        slow = head;
        for (; slow!=fast; ) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

int main() {
    return 0;
}