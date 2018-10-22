#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) {
            return n==0? 0:1;
        }

        int nm2 = 1;
        int nm1 = 1;
        for (int i=2; i<n; i++) {
            int nm = nm2+nm1;
            nm2 = nm1;
            nm1 = nm;
        }
        return nm1+nm2;
    }
};

int main() {
    Solution s;

    std::cout<<s.climbStairs(3)<<std::endl;

    return 0;
}
