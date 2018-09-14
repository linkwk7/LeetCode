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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode * first = nullptr;
        ListNode * second = nullptr;
        ListNode * current = head;
        for (int i=0; i<n; i++) {
            if (i == m-2) {
                // Element before m
                first = current;
            }
            if (i == n-1) {
                second = current;
            }
            current = current->next;
        }

        ListNode * last = first;
        ListNode * next = second->next;


        if (last != nullptr) {
            ListNode * tail = reverseListUtil(first->next, second);
            tail->next = next;
            last->next = second;
        } else {
            ListNode * tail = reverseListUtil(head, second);
            tail->next = next;
            head = second;
        }

        return head;
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
    ListNode * lst = construct(std::vector<int> {1,2,3,4,5});

    Solution s;
    ListNode * head = s.reverseBetween(lst, 1, 4);

    printList(head);

    return 0;
}
