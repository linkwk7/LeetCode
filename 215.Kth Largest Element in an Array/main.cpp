#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // O(NlogN)
        // std::priority_queue<int, std::vector<int>, std::greater<int>> que;

        // if (nums.size() < k) {
        //     return -1;
        // }

        // for (auto iter=nums.begin(); iter!=nums.end(); iter++) {
        //     que.push(*iter);
        //     if (que.size() > k) {
        //         que.pop();
        //     }
        // }

        // return que.top();

        int l = 0;
        int r = nums.size()-1;
        int index = nums.size()-k;
        for (; true;) {
            int mid = partition(nums, l, r);
            if (mid == index) {
                return nums[mid];
            } else if (mid > index) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
    }

    int partition(std::vector<int> & nums, int l, int r) {
        int pivot = nums[l];
        int prev = l;
        int cur = l+1;

        for (; cur <= r; cur++) {
            if (nums[cur] < pivot) {
                std::swap(nums[++prev], nums[cur]);
            }
        }
        std::swap(nums[l], nums[prev]);
        return prev;
    }
};

int main() {
    std::vector<int> data {3,2,1,5,6,4};

    Solution s;
    std::cout<<s.findKthLargest(data, 2);

    return 0;
}
