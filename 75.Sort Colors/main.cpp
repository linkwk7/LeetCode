#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one = 0;
        int two = nums.size()-1;

        for (int i=0; i<=two; i++) {
            if (nums[i] == 0) {
                std::swap(nums[i], nums[one]);
                one++;
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[two]);
                two--;
                i--;
            }
        }
    }
};

int main() {
    std::vector<int> data {2,0,1};
    Solution s;
    s.sortColors(data);

    std::for_each(data.begin(), data.end(), [](int arg) {
        std::cout<<arg<<" ";
    });

    return 0;
}
