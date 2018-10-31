#include <iostream>
#include <vector>

using std::vector;

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        std::vector<ListNode*> parts(k, NULL);
        int len = 0;
        for (ListNode* node = root; node; node = node->next) {
            len++;
        }
        int n = len / k, r = len % k;
        ListNode* node = root, *prev = nullptr;
        for (int i = 0; node && i < k; i++, r--) {
            parts[i] = node;
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return parts;
    }
};

int main() {
    Solution s;

    ListNode * head = construct(std::vector<int> {1,2,3,4,5,6,7,8,9,10});
    auto result = s.splitListToParts(head, 3);

    for (ListNode * p : result) {
        std::cout<<p->val<<",";
    }

    return 0;
}