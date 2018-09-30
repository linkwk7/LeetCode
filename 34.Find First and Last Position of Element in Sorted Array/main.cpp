#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size()-1;
        int index = -1;

        for (; first<=last;) {
            int mid = (first+last)/2;

            if (nums[mid] < target) {
                first = mid+1;
            } else if (nums[mid] > target) {
                last = mid-1;
            } else {
                index = mid;
                break;
            }
        }

        std::vector<int> result {-1,-1};
        if (index != -1) {
            for (int i=index; i>=0 && nums[i]==target; i--) {
                result[0] = i;
            }
            for (int i=index; i<nums.size() && nums[i]==target; i++) {
                result[1] = i;
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> data {5,7,7,8,8,10};
    Solution s;
    std::vector<int> res = s.searchRange(data,6);
    std::cout<<res[0]<<" "<<res[1]<<std::endl;

    return 0;
}
