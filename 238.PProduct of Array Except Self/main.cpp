#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> leftProduct(nums.size(),1);
        std::vector<int> rightProduct(nums.size(), 1);

        for (int i=0,sz=nums.size(); i<sz-1; i++) {
            leftProduct[i+1] = leftProduct[i]*nums[i];
            rightProduct[sz-i-2] = rightProduct[sz-i-1]*nums[sz-i-1];
        }

        std::vector<int> result(nums.size());
        for (int i=0,sz=nums.size(); i<sz; i++) {
            result[i] = leftProduct[i]*rightProduct[i];
        }
        return result;
    }
};

int main() {
    Solution s;

    std::vector<int> data {1,2,3,4};
    auto result = s.productExceptSelf(data);
    for (int elem : result) {
        std::cout<<elem<<",";
    }
    std::cout<<std::endl;

    return 0;
}
