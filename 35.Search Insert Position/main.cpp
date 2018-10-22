#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size()-1;

        for (; first<=last; ) {
            int mid = (first+last)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                first = mid+1;
            } else {
                last = mid-1;
            }
        }

        return first;
    }
};

int main() {
    std::vector<int> data {1,3,5,6};

    Solution s;

    std::cout<<s.searchInsert(data, 5)<<std::endl;
    std::cout<<s.searchInsert(data, 2)<<std::endl;
    std::cout<<s.searchInsert(data, 7)<<std::endl;
    std::cout<<s.searchInsert(data, 0)<<std::endl;

    return 0;
}