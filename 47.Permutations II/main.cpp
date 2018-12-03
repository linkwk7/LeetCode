#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::vector<std::vector<int>> result;

        std::sort(nums.begin(), nums.end());
        
        permuteUniqueAux(nums, 0, result);

        return result;
    }

    void permuteUniqueAux(std::vector<int> nums, int pos, std::vector<std::vector<int>> & result) {
        if (pos == nums.size()-1) {
            result.push_back(nums);
            return;
        }

        for (int i=pos,sz=nums.size(); i<sz; i++) {
            if (i>pos && nums[i]==nums[pos]) {
                continue;
            }

            std::swap(nums[i], nums[pos]);
            permuteUniqueAux(nums, pos+1, result);
        }
    }
};

int main() {
    Solution s;

    std::vector<int> data {1,1,2,2};
    auto result = s.permuteUnique(data);

    for (auto lst : result) {
        for (int elem : lst) {
            std::cout<<elem<<",";
        }
        std::cout<<std::endl;
    }

    return 0;
}
