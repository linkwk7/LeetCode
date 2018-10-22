#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int currentSum = nums[0];
        // int maxSum = currentSum;
        // for (int i=1,sz=nums.size(); i<sz; i++) {
        //     if (currentSum < 0) {
        //         currentSum = nums[i];
        //     } else {
        //         currentSum += nums[i];
        //     }
        //     if (currentSum > maxSum) {
        //         maxSum = currentSum;
        //     }
        // }

        // return maxSum;
    
        return maxSubArrayAux(nums, 0, nums.size()-1);
    }

    int maxSubArrayAux(const std::vector<int>& nums, int begin, int end) {
        if (begin > end) {
            return -2100000000;
        } else if (begin == end) {
            return nums[begin];
        }
        
        int mid = (begin+end)/2;
        int leftMax = maxSubArrayAux(nums, begin, mid-1);
        int rightMax = maxSubArrayAux(nums, mid+1, end);
        int crossMax = maxSubArrayCross(nums,mid);

        return std::max({leftMax, rightMax, crossMax});
    }

    int maxSubArrayCross(const std::vector<int>& nums, int mid) {
        int sum = nums[mid];
        int maxSum = sum;
        for (int i=mid-1; i>=0; i--) {
            sum += nums[i];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
        sum = maxSum;
        for (int i=mid+1; i<nums.size(); i++) {
            sum += nums[i];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
        return maxSum;
    }
};

int main() {
    std::vector<int> data {-2,1,-3,4,-1,2,1,-5,4};

    Solution s;

    std::cout<<s.maxSubArray(data)<<std::endl;

    return 0;
}