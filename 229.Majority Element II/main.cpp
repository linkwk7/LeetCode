#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majority0 = 0;
        int majority1 = 1;
        int count0 = 0;
        int count1 = 0;

        for (int i=0,sz=nums.size(); i<sz; i++) {
            if (nums[i] == majority0) {
                count0++;
            } else if (nums[i] == majority1) {
                count1++;
            } else if (count0 == 0) {
                majority0 = nums[i];
                count0 = 1;
            } else if (count1 == 0) {
                majority1 = nums[i];
                count1 = 1;
            } else {
                count0--;
                count1--;
            }
        }

        count0 = 0;
        count1 = 0;
        for (int i=0,sz=nums.size(); i<sz; i++) {
            if (nums[i] == majority0) {
                count0++;
            } else if (nums[i] == majority1) {
                count1++;
            }
        }

        std::vector<int> result;
        if (count0 > nums.size()/3) {
            result.push_back(majority0);
        }
        if (count1 > nums.size()/3) {
            result.push_back(majority1);
        }
        return result;
    }
};

int main() {
    std::vector<int> data {
        1,1,1,3,3,2,2,2
    };
    
    Solution s;
    std::vector<int> result = s.majorityElement(data);
    
    for (int i=0; i<result.size(); i++) {
        std::cout<<result[i]<<" ";
    }

    return 0;
}