#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;

        for (; l<r; ) {
            int mid = (l+r)/2;

            if (nums[mid] < nums[r]) {
                r = mid;
            } else if (nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r--;
            }
        }
        return nums[l];
    }
};

int main() {
    std::vector<int> data {2, 1};
    Solution s;
    std::cout<<s.findMin(data)<<std::endl;

    return 0;
}