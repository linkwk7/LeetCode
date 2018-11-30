#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int v = x;
        int pow = 0;
        for (; v!=0; v/=10) {
            pow = (pow==0 ? 1:pow*10);
        }

        int n = x;
        for (; x!=0; ) {
            if (x/pow != n%10) {
                return false;
            }
            x %= pow;
            pow /= 10;
            n /= 10;
        }
        return true;
    }
};

int main() {
    Solution s;

    std::cout<<s.isPalindrome(123);

    return 0;
}