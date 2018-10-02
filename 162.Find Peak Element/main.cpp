#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int first = 0;
        int last = nums.size()-1;

        for (; first<last; ) {
            int mid = (first+last)/2;
            int midp = mid+1;

            if (nums[mid] < nums[midp]) {
                first = midp;
            } else {
                last = mid;
            }
        }

        return first;
    }
};

int main() {
    std::vector<int> data {
        1,2,3,1
    };

    Solution s;
    std::cout<<s.findPeakElement(data)<<std::endl;

    return 0;
}
