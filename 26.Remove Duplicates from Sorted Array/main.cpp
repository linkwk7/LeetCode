#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int lastWrite = 1;
        int lastUnique = nums[0];
        for (int i=1,sz=nums.size(); i<sz; i++) {
            if (nums[i] != lastUnique) {
                lastUnique = nums[i];
                nums[lastWrite] = nums[i];
                lastWrite++;
            }
        }
        return lastWrite;
    }
};

int main() {
    Solution s;

    std::vector<int> data {0,0,1,1,1,2,2,3,3,4};

    int n = s.removeDuplicates(data);

    for (int i=0; i<n; i++) {
        std::cout<<data[i]<<" ";
    }

    return 0;
}