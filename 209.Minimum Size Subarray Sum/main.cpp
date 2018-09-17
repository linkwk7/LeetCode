#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int first = 0;
        int last = 0;

        int min = nums.size()+1;
        int currentSum = 0;
        for (int sz=nums.size(); last<sz; last++) {
            // [first, last]
            currentSum += nums[last];

            if (currentSum >= s) {
                if (last-first+1 < min) {
                    min = last-first+1;
                }

                for (; first<last; ) {
                    currentSum -= nums[first];
                    first++;

                    if (currentSum < s) {
                        break;
                    }

                    // [first+1, last]
                    if (last-first+1 < min) {
                        min = last-first+1;
                    }
                }
            }
        }
        return (min==nums.size()+1 ? 0:min);
    }
};

int main() {
    std::vector<int> data {1, 1};

    Solution s;
    std::cout<<s.minSubArrayLen(3, data);

    return 0;
}
