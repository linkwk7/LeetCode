#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i=0; i<sizeof(int)*8; i++) {
            int mask = 1<<i;
            int count = 0;
            for (int j=0,sz=nums.size(); j<sz; j++) {
                if ((nums[j] & mask) != 0) {
                    count++;
                }
            }
            if (count % 3 != 0) {
                result |= mask;
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> data {0,1,0,1,0,1,99};
    
    Solution s;

    std::cout<<s.singleNumber(data);

    return 0;
}