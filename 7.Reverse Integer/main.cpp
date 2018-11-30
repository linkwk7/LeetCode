#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int num = 0;
        for (; x!=0; ) {
            int n = num;
            num *= 10;
            num += x%10;
            if ((num-(x%10))/10 != n) {
                return 0;
            }
            x /= 10;
        }
        return (x < 0 ? -num:num);
    }
};

int main() {
    Solution s;

    std::cout<<s.reverse(1534236469);

    return 0;
}
