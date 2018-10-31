#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> result;
        std::vector<int> path;
        subsetsWithDupAux(result, path, nums, 0);
        return result;
    }

    void subsetsWithDupAux(std::vector<std::vector<int>> & result, std::vector<int> path, const std::vector<int> & nums, int current) {
        result.push_back(path);
        for (int i=current; i<nums.size(); i++) {
            if (i > current && nums[i]==nums[i-1]) {
                continue;
            }
            path.push_back(nums[i]);
            subsetsWithDupAux(result, path, nums, i+1);
            path.pop_back();
        }
    }
};

int main() {
    std::vector<int> data {
        1,2,2
    };

    Solution s;
    std::vector<std::vector<int>> result = s.subsetsWithDup(data);

    std::for_each(result.begin(), result.end(), [](const std::vector<int> & arg) {
        std::for_each(arg.begin(), arg.end(), [](int ar) {
            std::cout<<ar<<" ";
        });
        std::cout<<std::endl;
    });

    return 0;
}
