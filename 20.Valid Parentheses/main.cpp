#include <iostream>
#include <string>
#include <stack>

using std::string;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parenthese;
        for (char c : s) {
            if (isLeftParenthese(c)) {
                parenthese.push(c);
            } else if (isRightParenthese(c)) {
                if (parenthese.empty() || !isValidAux(parenthese.top(), c)) {
                    return false;
                }
                parenthese.pop();
            }
        }
        return parenthese.empty();
    }

    bool isLeftParenthese(char c) {
        return c=='('||c=='{'||c=='[';
    }

    bool isRightParenthese(char c) {
        return c==')'||c=='}'||c==']';
    }

    bool isValidAux(char lhs, char rhs) {
        switch(lhs) {
            case '(':
                return rhs==')';
            case '{':
                return rhs=='}';
            case '[':
                return rhs==']';
        }
        return false;
    }
};

int main() {
    Solution s;

    std::cout<<s.isValid("()[]{}")<<std::endl;
    std::cout<<s.isValid("([)]")<<std::endl;

    return 0;
}