#include <iostream>
#include <stack>

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        _stk0.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        transferBetweenStack();
        int top = _stk1.top();
        _stk1.pop();
        return top;
    }

    /** Get the front element. */
    int peek() {
        transferBetweenStack();
        return _stk1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return _stk0.empty()&&_stk1.empty();
    }
private:
    void transferBetweenStack() {
        if (_stk1.empty()) {
            for (; !_stk0.empty(); _stk0.pop()) {
                _stk1.push(_stk0.top());
            }
        }
    }

    std::stack<int> _stk0;
    std::stack<int> _stk1;
};

int main() {
    MyQueue que;
    que.push(1);
    int top = que.pop();
    que.push(2);
    int peek = que.peek();
    std::cout<<top<<" "<<peek<<std::endl;

    return 0;
}
