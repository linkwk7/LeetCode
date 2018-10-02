#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int count = 0;
        for (int first=0,sz=nums.size(); first<sz; first++) {
            if (nums[first] == 0) {
                continue;
            }
            for (int second=first+2; second<sz; second++) {
                int third = first+1;
                for (; third<second; third++) {
                    if (nums[third] > (nums[second]-nums[first])) {
                        break;
                    }
                }
                std::cout<<first<<" "<<third<<" "<<second<<std::endl;
                count += (second-third);
            }
        }
        return count;
    }
};

int main() {
    std::vector<int> data {
        0,1,0
    };

    Solution s;
    std::cout<<s.triangleNumber(data)<<std::endl;

    return 0;
}
