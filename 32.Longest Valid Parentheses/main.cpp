#include <iostream>
#include <string>
#include <stack>

using std::string;

class Solution {
public:
    int longestValidParentheses(string s) {
        std::stack<int> stk;
        for (int i=0,sz=s.size(); i<sz; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (stk.empty() || s[stk.top()]!='(') {
                    stk.push(i);
                } else {
                    stk.pop();
                }
            }
        }
        if (stk.empty()) {
            return s.size();
        }
        int longest = 0;
        int end = s.size();
        for (; !stk.empty(); ) {
            longest = std::max(longest, end-stk.top()-1);
            end = stk.top();
            stk.pop();
        }
        longest = std::max(end, longest);

        return longest;
    }
};

int main() {
    Solution s;

    std::cout<<s.longestValidParentheses("()");

    return 0;
}
