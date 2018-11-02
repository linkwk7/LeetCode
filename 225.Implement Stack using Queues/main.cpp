#include <iostream>
#include <queue>

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        _que.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        for (int i=0,sz=_que.size()-1; i<sz; i++) {
            _que.push(_que.front());
            _que.pop();
        }
        int front = _que.front();
        _que.pop();
        return front;
    }
    
    /** Get the top element. */
    int top() {
        for (int i=0,sz=_que.size()-1; i<sz; i++) {
            _que.push(_que.front());
            _que.pop();
        }
        int front = _que.front();
        _que.push(_que.front());
        _que.pop();
        return front;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return _que.empty();
    }
private:
    std::queue<int> _que;
};

int main() {

}