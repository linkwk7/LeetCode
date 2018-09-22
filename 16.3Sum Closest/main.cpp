#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0]+nums[1]+nums[2];
        for (int i=0, sz=nums.size()-2; i<sz; i++) {
            int twoSum = twoSumCloset(nums, i+1, target-nums[i]);
            if (std::abs(nums[i]+twoSum-target) < std::abs(closest-target)) {
                closest = nums[i]+twoSum;
            }
        }

        return closest;
    }

    int twoSumCloset(vector<int> & nums, int begin, int target) {

        int closest = nums[begin]+nums[begin+1];
        for (int i=begin, sz=nums.size(); i<sz; i++) {
            for (int j=i+1; j<sz; j++) {
                if (std::abs(nums[i]+nums[j] - target) < std::abs(closest-target)) {
                    closest = nums[i]+nums[j];
                }
            }
        }

        return closest;
    }
};

int main() {
    std::vector<int> data {1,1,1,0};

    Solution s;
    std::cout<<s.threeSumClosest(data, 100)<<std::endl;

    return 0;
}
