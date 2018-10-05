#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        for (; slow != fast; ) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;
        for (; slow != fast; ) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
    std::vector<int> data {1,3,4,2,2};

    Solution s;
    std::cout<<s.findDuplicate(data)<<std::endl;

    return 0;
}