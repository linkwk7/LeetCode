#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        permuteUniqueAux(result, nums, 0);
        return result;
    }

    void permuteUniqueAux(std::vector<std::vector<int>> & result, std::vector<int> nums, int current) {
        if (current >= nums.size()) {
            result.push_back(nums);
        } else {
            for (int i=current,sz=nums.size(); i<sz; i++) {
                bool exist = false;
                for (int k=current; k<i; k++) {
                    if (nums[k] == nums[i]) {
                        exist = true;
                        break;
                    }
                }
                if (!exist) {
                    std::swap(nums[current], nums[i]);
                    permuteUniqueAux(result, nums, current+1);
                    std::swap(nums[current], nums[i]);
                }
            }
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
