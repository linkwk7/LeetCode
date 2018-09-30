#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 2) {
            return true;
        }

        std::vector<int> jumps(nums.size(), -1);
        jumps[nums.size()-1] = 0;

        for (int i=nums.size()-2; i>=0; i--) {
            if (nums[i] < 1) {
                continue;
            }

            int min = -1;
            for (int index=1; index<=nums[i] && (i+index)<nums.size(); index++) {
                if (min == -1 || (jumps[i+index]<min && jumps[i+index]!=-1)) {
                    min = jumps[i+index];
                }
            }
            jumps[i] = (min==-1 ? -1:min+1);
        }

        std::for_each(jumps.begin(), jumps.end(), [](int arg) {
            std::cout<<arg<<" ";
        });
        std::cout<<std::endl;

        return jumps[0] != -1;
    }
};

int main() {
    std::vector<int> data {2,5,0,0};
    Solution s;
    std::cout<<s.canJump(data)<<std::endl;

    return 0;
}
