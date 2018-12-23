#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        sortListAux(head, NULL);
        return head;
    }

    void sortListAux(ListNode* head, ListNode* tail) {
        if (head == tail || head->next == tail) {
            return;
        }

        ListNode* mid = partition(head, tail);
        sortListAux(head, mid);
        sortListAux(mid->next,tail);
    }

    ListNode* partition(ListNode* head, ListNode* tail) {
        ListNode* pre = head;
        int pivot = head->val;
        for(ListNode* current=head->next; current!=tail; current=current->next) {
            if (current->val < pivot) {
                pre = pre->next;
                std::swap(pre->val, current->val);
            }
        }
        std::swap(pre->val, head->val);
        return pre;
    }
};

int main() {

}