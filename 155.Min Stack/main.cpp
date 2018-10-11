#include <iostream>
#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() : _iMin(0) {
    }
    
    void push(int x) {
        if (_oData.size() == 0) {
            _oData.push(0L);
            _iMin = x;
        } else {
            _oData.push(static_cast<long int>(x)-_iMin);
            if (x < _iMin) {
                _iMin = x;
            }
        }
    }
    
    void pop() {
        if (_oData.size() > 0) {
            if (_oData.top() < 0) {
                _iMin -= _oData.top();
            }
            _oData.pop();
        }
    }
    
    int top() {
        if (_oData.top() < 0) {
            return _iMin;
        } else {
            return static_cast<long int>(_oData.top())+_iMin;
        }
    }
    
    int getMin() {
        return _iMin;
    }

private:
    std::stack<long int> _oData;
    long int _iMin;
};

int main() {
    MinStack stk;
    stk.push(1);
    std::cout<<stk.top()<<std::endl;
    stk.push(-1);
    std::cout<<stk.getMin()<<std::endl;

    return 0;
}