#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }

        int i = nums.size()-1;
        for (; i>=1 && nums[i]<=nums[i-1]; i--) {}

        int swap = nums.size()-1;
        for (; swap>=i && nums[swap] <= nums[i-1]; swap--) {}

        if (i != 0) {
            std::swap(nums[i-1], nums[swap]);
        }

        reverse(nums, i);
    }

    void reverse(std::vector<int> & nums, int begin) {
        for (int i=begin,j=nums.size()-1; i<j; i++,j--) {
            std::swap(nums[i], nums[j]);
        }
    }
};

int main() {
    Solution s;
    std::vector<int> data {5, 1, 1};
    s.nextPermutation(data);

    for (int i=0; i<data.size(); i++) {
        std::cout<<data[i]<<" ";
    }

    return 0;
}
