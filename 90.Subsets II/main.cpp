#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> result {{}};
        std::vector<std::vector<int>> current;

        for (int i=0,sz=nums.size(); i<sz; i++) {
            if (i==0 || nums[i]!=nums[i-1]) {
                current = result;

                for (int len=0, index=i; index<sz && nums[index]==nums[i]; index++) {
                    for (int subIndex=0,s=current.size(); subIndex<s; subIndex++) {
                        current[subIndex].push_back(nums[i]);
                        result.push_back(current[subIndex]);
                    }
                }
            }
        }

        return result;
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
