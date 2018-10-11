#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 1) {
            return 0;
        } else if (nums.size() < 2) {
            return nums[0];
        }

        int i2 = nums.back();
        int i1 = std::max(nums[nums.size()-2], i2);
        for (int i=nums.size()-3; i>=0; i--) {
            int i0 = std::max(nums[i]+i2, i1);
            i2 = i1;
            i1 = i0;
        }
        return i1;
    }
};

int main() {
    std::vector<int> data {2,7,9,3,1};

    Solution s;
    std::cout<<s.rob(data)<<std::endl;

    return 0;
}