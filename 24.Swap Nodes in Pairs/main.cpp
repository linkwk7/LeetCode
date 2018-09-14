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
        ListNode * last = nullptr;
        ListNode * first = head;
        if (first == NULL) {
            return head;
        }
        ListNode * second = head->next;
        for (; first!=NULL && second!=NULL;) {
            if (last == nullptr) {
                head = second;
            } else {
                last->next = second;
            }

            ListNode * next = second->next;
            second->next = first;
            first->next = next;
            last = first;

            first = first->next;
            if (first == NULL) {
                break;
            }
            second = first->next;
        }

        return head;
    }
};

int main() {
    ListNode * lst = construct(std::vector<int> {1});

    Solution s;
    lst = s.swapPairs(lst);

    printList(lst);

    return 0;
}
