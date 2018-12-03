#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result(1, std::vector<int>());
        
        for (int i=0,sz=nums.size(); i<sz; i++) {
            int resz = result.size();
            for (int j=0; j<resz; j++) {
                result.push_back(result[j]);
            }
            for (int j=0; j<resz; j++) {
                (result.begin()+j)->push_back(nums[i]);
            }
        }

        return result;
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