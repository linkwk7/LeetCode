#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
        bool search(vector<int>& nums, int target) {
            int first = 0;
            int last = nums.size()-1;

            for (; first<=last; ) {
                int mid = (first+last)/2;

                if (nums[mid] == target) {
                    return true;
                }

                if (nums[mid] < nums[last] || nums[mid]<nums[first]) {
                    if (target >= nums[mid] && target<=nums[last]) {
                        first = mid+1;
                    } else {
                        last = mid-1;
                    }
                } else if (nums[mid] > nums[first] || nums[mid] < nums[last]) {
                    if (target < nums[mid] && target>=nums[first]) {
                        last = mid-1;
                    } else {
                        first = mid+1;
                    }
                } else {
                    first++;
                }
            }

            return false;
        }
};

int main() {
    Solution s;
    std::vector<int> data {2,5,6,0,0,1,2};
    std::cout<<s.search(data, 3)<<std::endl;

    return 0;
}
