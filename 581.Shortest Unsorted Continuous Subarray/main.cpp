#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int max = nums.front();
        int end = -1;
        for (int i=1,sz=nums.size(); i<sz; i++) {
            max = std::max(max, nums[i]);
            if (nums[i] < max) {
                end = i;
            }
        }
        int beg = 0;
        int min = nums.back();
        for (int i=nums.size()-2; i>=0; i--) {
            min = std::min(min, nums[i]);
            if (nums[i] > min) {
                beg = i;
            }
        }
        return end-beg+1;
    }
};

int main() {
    Solution s;
    std::vector<int> data {2, 6, 4, 8, 10, 9, 15};

    std::cout<<s.findUnsortedSubarray(data);

    return 0;
}