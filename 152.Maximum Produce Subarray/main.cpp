#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int lastSmallest = nums[0];
        int lastLargest = nums[0];

        int maxPro = nums[0];
        for (int i=1; i<nums.size(); i++) {
            int val0 = lastSmallest*nums[i];
            int val1 = lastLargest*nums[i];

            lastSmallest = std::min({val0, val1, nums[i]});
            lastLargest = std::max({val0, val1, nums[i]});

            maxPro = std::max(lastLargest, maxPro);
        }

        return maxPro;
    }
};

int main() {
    std::vector<int> data {
        -1,0,-2
    };

    Solution s;
    std::cout<<s.maxProduct(data)<<std::endl;

    return 0;

}
