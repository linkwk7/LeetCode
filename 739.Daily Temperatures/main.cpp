#include <iostream>
#include <vector>
#include <stack>

using std::vector;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        std::vector<int> result(T.size(), 0);
        std::stack<int> stk;

        for (int i=0,sz=T.size(); i<sz; i++) {
            for (; !stk.empty() && T[i]>T[stk.top()];) {
                result[stk.top()] = i-stk.top();
                stk.pop();
            }
            stk.push(i);
        }

        return result;
    }
};

int main() {
    Solution s;

    std::vector<int> data {73, 74, 75, 71, 69, 72, 76, 73};

    auto result = s.dailyTemperatures(data);

    for (int elem : result) {
        std::cout<<elem<<",";
    }

    return 0;
}
