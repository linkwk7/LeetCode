#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        std::vector<int> dp (target+1, 0);

        dp[0] = 1;
        for (int i=1; i<=target; i++) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] += dp[i-num];
                }
            }
        }
        return dp[target];
    }
};

int main() {
    Solution s;
    
    std::vector<int> data {1,2,3};

    std::cout<<s.combinationSum4(data, 4)<<std::endl;

    return 0;
}