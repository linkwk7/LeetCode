#include <iostream>
#include <vector>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode * construct(const std::vector<int> & list) {
    RandomListNode * head = nullptr;
    RandomListNode * current = nullptr;
    for (auto iter=list.begin(); iter!=list.end(); iter++) {
        if (head == nullptr) {
            head = new RandomListNode(*iter);
            current = head;
        } else {
            current->next = new RandomListNode(*iter);
            current = current->next;
        }
    }
    return head;
}

void printList(RandomListNode * lst) {
    for (; lst!=NULL; lst=lst->next) {
        std::cout<<lst->label<<",";
    }
}

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for (RandomListNode * current=head; current!=NULL;) {
            RandomListNode * next = current->next;

            current->next = new RandomListNode(current->label);
            current->next->next = next;
            
            current = next;
        }

        if (head == NULL) {
            return NULL;
        }

        RandomListNode * cHead = head->next;
        bool isOdd = true;
        for (RandomListNode * current=head; current!=NULL; current=current->next, isOdd=!isOdd) {
            if (isOdd) {
                current->next->random = (current->random==NULL ? NULL:current->random->next);
            }
        }

        RandomListNode * last = nullptr;
        isOdd = true;
        for (RandomListNode * current = head; current!=NULL; ) {
            if (isOdd) {
                last = current;
            } else {
                last->next = current->next;
                current->next = (current->next==NULL? NULL: current->next->next);
            }
            isOdd = !isOdd;
        
            current = last->next;
        }

        return cHead;
    }
};

int main() {
    RandomListNode * head = construct(std::vector<int> {1});

    Solution s;
    RandomListNode * cHead = s.copyRandomList(head);

    printList(head);
    std::cout<<std::endl;
    printList(cHead);

    return 0;
}
