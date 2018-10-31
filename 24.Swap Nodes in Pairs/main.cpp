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
    ListNode* swapPairs(ListNode* head) {
        ListNode * current = head;
        ListNode * last = NULL;
        for (; current!=NULL && current->next!=NULL; ) {
            ListNode * next = current->next;
            ListNode * afterNext = next->next;
            next->next = current;
            current->next = afterNext;
            if (last == NULL) {
                head = next;
            } else {
                last->next = next;
            }
            last = current;
            current = afterNext;
        }
        return head;
    }
};

int main() {
    ListNode * lst = construct(std::vector<int> {1,2,3,4,5,6});

    Solution s;
    lst = s.swapPairs(lst);

    printList(lst);

    return 0;
}
