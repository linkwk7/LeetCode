#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0];
        int count = 1;

        for (int i=1,sz=nums.size(); i<sz; i++) {
            if (count == 0) {
                maj = nums[i];
                count = 1;
            } else if (nums[i] != maj) {
                count--;
            } else {
                count++;
            }
        }
        return maj;
    }
};

int main() {
    std::vector<int> data {2,2,1,1,1,2,2};

    Solution s;
    std::cout<<s.majorityElement(data);

    return 0;
}
