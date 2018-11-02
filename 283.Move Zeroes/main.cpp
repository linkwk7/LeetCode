#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int prev = -1;
        for (int current=0,sz=nums.size(); current<sz; current++) {
            if (nums[current]!=0) {
                prev++;
                std::swap(nums[prev], nums[current]);
            }
        }
        return;
    }
};

int main() {
    Solution s;

    std::vector<int> data {0,1,0,3,12};
    s.moveZeroes(data);

    for (int elem : data) {
        std::cout<<elem<<",";
    }

    return 0;
}