#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());        
        int count = 0;
        for (int l=0,r=nums.size()-1; l<r; l++,r--) {
            count += nums[r]-nums[l];
        }
        return count;
    }
};

int main() {

}