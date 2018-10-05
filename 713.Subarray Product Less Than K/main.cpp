#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 0) {
            return 0;
        }

        int first = 0;
        int last = 0;

        int count = 0;
        int product = 1;
        for (; last<nums.size(); ) {
            product *= nums[last];
            last++;

            for (; product>=k; ) {
                product /= nums[first];
                first++;
            }

            count += (last-first);
        }

        return count;
    }
};

int main() {
    std::vector<int> data {1,1,1};

    Solution s;
    std::cout<<s.numSubarrayProductLessThanK(data, 1)<<std::endl;

    return 0;
}
