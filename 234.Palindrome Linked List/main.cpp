#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int len = 0;
        for (ListNode * current=head; current!=NULL; current=current->next) {
            len++;
        }
        std::stack<int> stk;
        ListNode * current = head;
        for (int i=0,sz=len/2; i<sz; i++) {
            stk.push(current->val);
            current = current->next;
        }

        if (len % 2 != 0) {
            current = current->next;
        }

        for (; !stk.empty(); ) {
            if (current->val != stk.top()) {
                return false;
            }
            stk.pop();
            current = current->next;
        }
        return true;
    }
};

int main() {

}