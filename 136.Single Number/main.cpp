#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for (int i=0,sz=nums.size(); i<sz; i++) {
            n^=nums[i];
        }
        return n;
    }
};

int main() {

}