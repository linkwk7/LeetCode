#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> result;

        for (int i=0,sz=nums.size(); i<sz-3; i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                std::vector<std::vector<int>> pairs;

                threeSum(nums, i+1, target-nums[i], pairs);

                for (int j=0,s=pairs.size(); j<s; j++) {
                    result.push_back(std::vector<int> {nums[i], pairs[j][0], pairs[j][1], pairs[j][2]});
                }
            }
        }

        return result;
    }

    void threeSum(vector<int>& nums, int begin, int target, std::vector<std::vector<int>> & result) {
        for (int i=begin,sz=nums.size(); i<sz-2; i++) {
            if (i == begin || nums[i] != nums[i-1]) {
                std::vector<std::vector<int>> pairs;
                twoSum(nums, i+1, target-nums[i], pairs);

                for (int j=0,s=pairs.size(); j<s; j++) {
                    result.push_back(std::vector<int> {nums[i], pairs[j][0], pairs[j][1]});
                }
            }
        }
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
    std::vector<int> nums {-3,-2,-1,0,0,1,2,3};

    Solution s;
    std::vector<std::vector<int>> res = s.fourSum(nums, 0);

    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            std::cout<<res[i][j]<<",";
        }
        std::cout<<std::endl;
    }
}
