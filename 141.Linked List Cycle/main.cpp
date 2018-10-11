#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;

        do {
            if (slow == NULL || fast == NULL) {
                return false;
            }

            slow = slow->next;
            fast = fast->next;
            
            if (fast == NULL) {
                return false;
            }

            fast = fast->next;

        } while (slow != fast);
        return true;
    }
};

int main() {
    return 0;
}