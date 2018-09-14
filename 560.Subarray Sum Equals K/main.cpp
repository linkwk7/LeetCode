#include <iostream>
#include <vector>
#include <map>

using std::vector;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::map<int, int> counts;
        int sum = 0;
        int count = 0;

        counts[0] = 1;

        for (int i=0, sz=nums.size(); i<sz; i++) {
            sum += nums[i];

            auto iter = counts.find(sum-k);
            if (iter != counts.end()) {
                count += iter->second;
            }

            counts[sum]++;
        }

        return count;
    }
};

int main() {
    std::vector<int> data {1, 1, 1};

    Solution s;
    std::cout<<s.subarraySum(data, 2)<<std::endl;

    return 0;
}
