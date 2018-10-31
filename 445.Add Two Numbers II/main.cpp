#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> num1;
        std::stack<int> num2;

        for (ListNode * l=l1; l!=NULL; l=l->next) {
            num1.push(l->val);
        }
        for (ListNode * l=l2; l!=NULL; l=l->next) {
            num2.push(l->val);
        }

        ListNode * last = NULL;
        int carry = 0;
        for (; !num1.empty() || !num2.empty() || carry != 0; ) {
            int n1 = 0;
            int n2 = 0;
            if (!num1.empty()) {
                n1 = num1.top();
                num1.pop();
            }
            if (!num2.empty()) {
                n2 = num2.top();
                num2.pop();
            }

            ListNode * newNode = new ListNode((n1+n2+carry)%10);
            newNode->next = last;
            last = newNode;
            carry = (n1+n2+carry)/10;
        }
        return last;
    }
};

int main() {
}