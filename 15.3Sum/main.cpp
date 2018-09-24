#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
    
        std::vector<std::vector<int>> result;
        for (int i=0,sz=nums.size(); i<sz-2; i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                std::vector<std::vector<int>> pairs;
                twoSum(nums, i+1, -nums[i], pairs);

                for (int j=0,s=pairs.size(); j<s; j++) {
                    result.push_back(std::vector<int> {nums[i], pairs[j][0], pairs[j][1]});
                }
            }
        }

        return result;
    }

    void twoSum(std::vector<int> & nums, int begin, int target, std::vector<std::vector<int>> & pairs) {
        int first = begin;
        int last = nums.size() - 1;

        for (; first<last; ) {
            int sum = nums[first]+nums[last];

            if (sum < target) {
                first++;
            } else if (sum > target) {
                last--;
            } else {
                pairs.push_back(std::vector<int> {nums[first], nums[last]});

                int recFirst = first;
                int recLast = last;
                for (; nums[first] == nums[recFirst]; first++) {}
                for (; nums[last]==nums[recLast]; last--) {}
            }
        }
    }
};

int main() {
    std::vector<int> data {0, 0, 0, 0};
    Solution s;
    std::vector<std::vector<int>> result = s.threeSum(data);
    std::for_each(result.begin(), result.end(), [](const std::vector<int> & arg) {
        for (int i=0,sz=arg.size(); i<sz; i++) {
            std::cout<<arg[i]<<",";
        }
        std::cout<<std::endl;
    });
}