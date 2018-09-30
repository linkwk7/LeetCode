#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int first = 0;
        int last = nums.size()-1;

        for (; first<last; ) {
            if (nums[first]<nums[last]) {
                break;
            }

            int mid = (first+last)/2;
            if (nums[mid] > nums[first]) {
                first = mid+1;
            } else {
                first++;
                last = mid;
            }
        }

        return nums[first];
    }
};

int main() {
    std::vector<int> data {2, 1};
    Solution s;
    std::cout<<s.findMin(data)<<std::endl;

    return 0;
}