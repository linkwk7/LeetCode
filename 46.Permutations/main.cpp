#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> result;

        permuteAux(nums, 0, result);

        return result;
    }

    void permuteAux(std::vector<int> & nums, int begin, std::vector<std::vector<int>> & result) {
        if (begin >= nums.size()-1) {
            result.push_back(nums);
        } else {
            for (int i=begin; i<nums.size(); i++) {
                std::swap(nums[begin], nums[i]);
                permuteAux(nums, begin+1, result);
                std::swap(nums[begin], nums[i]);
            }
        }
        return;
    }
};

int main() {
    std::vector<int> data {1,2,3};
    Solution s;
    std::vector<std::vector<int>> result = s.permute(data);

    std::for_each(result.begin(), result.end(), [](const std::vector<int> & arg) {
        std::for_each(arg.begin(), arg.end(), [](int ar) {
            std::cout<<ar<<" ";
        });
        std::cout<<std::endl;
    });

    return 0;
}
