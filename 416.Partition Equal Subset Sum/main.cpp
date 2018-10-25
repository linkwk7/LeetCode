#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i=0,sz=nums.size(); i<sz; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }
        sum /= 2;

        std::vector<bool> dp(sum+1, false);
        dp[0] = true;
        for (int i=0,sz=nums.size(); i<sz; i++) {
            for (int n=sum; n>=nums[i]; n--) {
                dp[n] = dp[n]||dp[n-nums[i]];
            }
        }
        return dp[sum];
    }
};

int main() {
    Solution s;
    std::vector<int> data {1,5,11,5};

    std::cout<<s.canPartition(data);

    return 0;
}
