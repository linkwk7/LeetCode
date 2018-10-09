#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        std::vector<int> dp(nums.size(), 1);

        int max = 1;
        for (int i=1; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i],dp[j]+1);
                    max = std::max(max, dp[i]);
                }
            }
        }

        return max;
    }
};

int main() {
    std::vector<int> data {1,3,6,7,9,4,10,5,6};

    Solution s;
    std::cout<<s.lengthOfLIS(data)<<std::endl;

    return 0;
}