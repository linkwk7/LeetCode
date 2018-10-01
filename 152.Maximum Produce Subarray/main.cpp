#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // First is max, second is minimum
        std::vector<std::pair<int,int>> prefixProduct(nums.size());

        prefixProduct[nums.size()-1] = std::make_pair(nums.back(), nums.back());

        int maxProduct = nums.back();
        for (int i=nums.size()-2; i>=0; i--) {
            int min = nums[i];
            int max = nums[i];

            int val0 = nums[i]*prefixProduct[i+1].first;
            int val1 = nums[i]*prefixProduct[i+1].second;

            prefixProduct[i].first = std::max({val0, val1, max});
            prefixProduct[i].second = std::min({val0, val1, min});

            if (prefixProduct[i].first > maxProduct) {
                maxProduct = prefixProduct[i].first;
            }
        }

        return maxProduct;
    }
};

int main() {
    std::vector<int> data {
        0,2
    };

    Solution s;
    std::cout<<s.maxProduct(data)<<std::endl;

    return 0;

}
