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
        int len = 0;
        for (ListNode * current = head; current!=NULL; current = current->next) {
            len++;
        }

        if (n == len) {
            return head->next;
        }

        int removed = len-n-1;
        ListNode * current = head;
        for (int i=0; i<removed; i++) {
            current = current->next;
        }

        current->next = current->next->next;
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