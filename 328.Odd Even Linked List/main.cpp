#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
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

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next==NULL) {
            return head;
        }

        ListNode * odd = head;
        ListNode * even = head->next;
        ListNode * current=even->next;
        for (; current!=NULL && current->next!=NULL;) {
            ListNode * next = current->next;
            ListNode * after = next->next;

            ListNode * evenHead = odd->next;
            odd->next = current;
            current->next = evenHead;
            odd = odd->next;
            even->next = next;
            even = next;
            current = after;
        }
        if (current != NULL) {
            ListNode * next =odd->next;
            odd->next = current;
            current->next = next;
            even->next = NULL;
        }
        return head;
    }
};

int main() {
    Solution s;
    ListNode * head =construct(std::vector<int> {1,2,3,4,5});

    auto h = s.oddEvenList(head);
    printList(h);

    return 0;
}
