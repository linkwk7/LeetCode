#include <iostream>
#include <vector>
#include <queue>

using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class ListNodeCompare {
public:
    bool operator() (const ListNode* lhs, const ListNode* rhs) {
        if (lhs == NULL) {
            return false;
        }
        if (rhs == NULL) {
            return true;
        }
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*,std::vector<ListNode*>,ListNodeCompare> heads(lists.begin(),lists.end());

        ListNode * last = NULL;
        ListNode * head = NULL;
        for (; !heads.empty(); ) {
            ListNode * current = heads.top();

            heads.pop();
            if (current != NULL) {
                if (last == NULL) {
                    head = current;
                } else {
                    last->next = current;
                }
                last = current;
                heads.push(current->next);
            }
        }

        return head;
    }
};

int main() {

}