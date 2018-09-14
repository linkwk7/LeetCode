#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;

        std::sort(nums.begin(), nums.end());

        fourSumUtil(nums, 0, target, 0, path, result);
    
        return result;
    }

    void fourSumUtil(std::vector<int> & nums, int begin, int target, int choosen, std::vector<int> & path, std::vector<std::vector<int>> & result) {
        if (choosen == 4 && target == 0) {
            if (std::find(result.rbegin(), result.rend(), path) == result.rend()) {
                result.push_back(path);
            }
            return;
        }

        if (choosen>=4 || nums.size()-begin < 4-choosen) {
            return;
        }

        if (begin >= nums.size()) {
            return;
        }

        path.push_back(nums[begin]);
        fourSumUtil(nums, begin+1, target-nums[begin], choosen+1, path, result);
        path.pop_back();

        fourSumUtil(nums, begin+1, target, choosen, path, result);

        return;
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
