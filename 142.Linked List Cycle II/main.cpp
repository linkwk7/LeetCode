#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode * slow = head;
        ListNode * fast = head;
    
        do {
            if (slow == NULL || fast == NULL) {
                return NULL;
            }

            slow = slow->next;
            fast = fast->next;

            if (fast == NULL) {
                return NULL;
            }
            fast = fast->next;
        } while(slow != fast);
    
        for (slow = head; slow != fast; ) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

int main() {
    return 0;
}