#include <iostream>

class Solution {
public:
    int countDigitOne(int n) {
        int sum = 0;
        int base = 1;
        for (int num = n; num != 0; ) {
            int higher = num/10;
            int current = num%10;
            int former = n%base;

            if (current > 1) {
                sum += (higher+1)*base;
            } else if (current == 1) {
                sum += higher*base + former + 1;
            } else {
                sum += higher*base;
            }

            num /= 10;
            base *= 10;
        }

        return sum;
    }
};

int main() {
    Solution s;

    std::cout<<s.countDigitOne(534)<<std::endl;

    return 0;
}