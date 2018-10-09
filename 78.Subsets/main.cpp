#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        subsetsAux(current, nums, 0, result);

        return result;
    }

    void subsetsAux(std::vector<int> & current, std::vector<int> & nums, int begin, std::vector<std::vector<int>> & result) {
        if (begin >= nums.size()) {
            result.push_back(current);
        } else {
            subsetsAux(current, nums, begin+1, result);
            current.push_back(nums[begin]);
            subsetsAux(current, nums, begin+1, result);
            current.pop_back();
        }
    }
};

int main() {
    std::vector<int> data {1,2,3};
    Solution s;
    std::vector<std::vector<int>> result = s.subsets(data);

    for (auto ve : result) {
        for (auto elem : ve) {
            std::cout<<elem<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}