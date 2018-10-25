#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetSumWaysAux(nums, 0, S);
    }

    int findTargetSumWaysAux(const std::vector<int>& nums, int begin, int S) {
        if (nums.size() == begin) {
            return S == 0;
        }
        return findTargetSumWaysAux(nums,begin+1, S+nums[begin])+findTargetSumWaysAux(nums, begin+1, S-nums[begin]);
    }
};

int main() {
    Solution s;
    std::vector<int> data {1,1,1,1,1};

    std::cout<<s.findTargetSumWays(data, 3);

    return 0;
}