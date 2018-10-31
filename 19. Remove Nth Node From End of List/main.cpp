#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode * slow = NULL;
        ListNode * fast = head;
        for (int i=0; i<n; i++) {
            fast = fast->next;
        }

        for (; fast!=NULL; ) {
            slow = (slow == NULL ? head:slow->next);
            fast = fast->next;
        }
        if (slow == NULL) {
            slow = head->next;
            delete head;
            return slow;
        }
        slow->next = slow->next->next;
        return head;
    }
};

ListNode * construct(const std::vector<int> & list) {
    ListNode * head = nullptr;
    ListNode * current = nullptr;
    for (auto iter=list.begin(); iter!=list.end(); iter++) {
        if (head == nullptr) {
            head = new ListNode(*iter);
            current = head;
        } else {
            current->next = new ListNode(*iter);
            current = current->next;
        }
    }
    return head;
}

void printList(ListNode * lst) {
    for (; lst!=NULL; lst=lst->next) {
        std::cout<<lst->val<<",";
    }
}

int main() {
    ListNode * head = construct(std::vector<int> {1,2});

    Solution s;
    head = s.removeNthFromEnd(head, 2);
    printList(head);

    return 0;
}