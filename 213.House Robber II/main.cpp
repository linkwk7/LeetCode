#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return std::max(nums[0], nums[1]);
        }
        
        int im2 = 0;
        int im1 = nums[1];
        for (int i=2,sz=nums.size(); i<sz; i++) {
            int max = std::max(im1, im2+nums[i]);
            im2 = im1;
            im1 = max;
        }
        int max = im1;

        im2 = nums[0];
        im1 = std::max(nums[0],nums[1]);
        for (int i=2,sz=nums.size(); i<sz-1; i++) {
            int max = std::max(im1, im2+nums[i]);
            im2 = im1;
            im1 = max;
        }
        return std::max(max, im1);
    }
};

int main() {
    std::vector<int> data {1,2,3,1};

    Solution s;

    std::cout<<s.rob(data)<<std::endl;

    return 0;
}