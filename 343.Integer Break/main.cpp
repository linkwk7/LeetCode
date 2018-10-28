#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int integerBreak(int n) {
        std::vector<int> dp(n+1, 0);
        dp[1] = 1;
        for (int i=2; i<=n; i++) {
            for (int j=1; j<i; j++) {
                dp[i] = std::max({dp[i], dp[i-j]*j, (i-j)*j});
            }
        }
        return dp.back();
    }
};

int main() {
    Solution s;

    std::cout<<s.integerBreak(10)<<std::endl;

    return 0;
}
