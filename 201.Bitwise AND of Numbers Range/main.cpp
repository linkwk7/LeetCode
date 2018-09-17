#include <iostream>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        for (int i=31; i>=0; i--) {
            int mask = 1<<i;
            if ((n & mask) > 0) {
                if ((m & mask) == 0) {
                    break;
                }
                result |= mask;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    std::cout<<s.rangeBitwiseAnd(5,7);

    return 0;
}