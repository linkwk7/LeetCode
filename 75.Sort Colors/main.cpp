#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int one = 0;
        // int two = nums.size()-1;

        // for (int i=0; i<=two; i++) {
        //     if (nums[i] == 0) {
        //         std::swap(nums[i], nums[one]);
        //         one++;
        //     } else if (nums[i] == 2) {
        //         std::swap(nums[i], nums[two]);
        //         two--;
        //         i--;
        //     }
        // }

        sortColorsAux(nums, 0, nums.size());
    }

    void sortColorsAux(std::vector<int> & nums, int l, int r) {
        if (l >= r) {
            return;
        }

        int pivot = nums[l];
        int eq = l;
        int gt = l;
        for (int i=l; i<r; i++) {
            if (nums[i] < pivot) {
                std::swap(nums[gt], nums[i]);
                std::swap(nums[gt], nums[eq]);
                eq++;
                gt++;
            } else if (nums[i] == pivot) {
                std::swap(nums[gt], nums[i]);
                gt++;
            }
        }

        sortColorsAux(nums, l, eq);
        sortColorsAux(nums, gt, r);
    }
};

int main() {
    std::vector<int> data {9,3,5,4,1,7,9,8,8,1,4,6,2,7,0,0};
    Solution s;
    s.sortColors(data);

    std::for_each(data.begin(), data.end(), [](int arg) {
        std::cout<<arg<<" ";
    });

    return 0;
}
