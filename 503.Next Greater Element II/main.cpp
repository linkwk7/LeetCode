#include <iostream>
#include <vector>
#include <stack>

using std::vector;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::stack<int> stk;
        std::vector<int> result(nums.size(), -1);
        for (int i=0,sz=nums.size()*2; i<sz; i++) {
            for (; !stk.empty() && nums[i%nums.size()]>nums[stk.top()];) {
                result[stk.top()] = nums[i%nums.size()];
                stk.pop();
            }
            stk.push(i%nums.size());
        }
        return result;
    }
};

int main() {
    Solution s;
    std::vector<int> data {1,2,1};

    auto result = s.nextGreaterElements(data);

    for (int elem : result) {
        std::cout<<elem<<",";
    }

    return 0;
}
