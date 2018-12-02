#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> appears;
        for (int i=0,sz=nums.size(); i<sz; i++) {
            auto iter = appears.find(target-nums[i]);
            if (iter == appears.end()) {
                appears[nums[i]] = i;
            } else {
                return std::vector<int> {iter->second, i};
            }
        }
        return std::vector<int>();
    }
};

int main() {
    Solution s;

    std::vector<int> data {2, 7, 11, 15};

    auto res = s.twoSum(data, 9);

    for (int elem : res) {
        std::cout<<elem<<" ";
    }

    return 0;
}