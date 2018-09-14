#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        ListNode * tail = nullptr;
        for (tail = head; tail->next != NULL; tail = tail->next) {
        }

        reverseListUtil(head, tail);
        head->next = NULL;
    
        return tail;
    }

    ListNode * reverseListUtil(ListNode * head, ListNode * tail) {
        if (head == tail) {
            return head;
        }
        
        ListNode * last = reverseListUtil(head->next, tail);
        last->next = head;

        return head;
    }
};

int main() {
    ListNode * head = construct(std::vector<int>{1,2,3,4,5});

    Solution s;
    head = s.reverseList(head);

    printList(head);

    return 0;
}