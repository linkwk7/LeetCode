#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }

        int left = 0;
        int right = nums.size()-1;

        for (; left<right; ) {
            int mid = (left+right)/2;

            if (nums[mid] > nums[right]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }

        if (target >= nums[0] && left!=0) {
            return binarySearch(nums,0, left, target);
        } else {
            return binarySearch(nums, left, nums.size(), target);
        }
    }

    int binarySearch(std::vector<int> & nums, int begin, int end, int target) {
        int left = begin;
        int right = end-1;

        for (; left<right; ) {
            int mid = (left+right)/2;
            if (nums[mid] < target) {
                left = mid+1;
            } else if (nums[mid] == target) {
                return mid;
            } else {
                right = mid;
            }
        }
        return (nums[left]==target ? left:-1);
    }
};

int main() {
    Solution s;
    std::vector<int> data {3,1};

    std::cout<<s.search(data, 1);
}
