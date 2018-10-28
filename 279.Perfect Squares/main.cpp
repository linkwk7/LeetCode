#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    int numSquares(int n) {
        std::vector<int> dp(n+1, 100000000);
        for (int i=1; i<=n; i++) {
            for (int j=1,end=static_cast<int>(std::sqrt(i)); j<=end; j++) {
                dp[i] = std::min(dp[i], dp[i-j*j]+1);
                if (i%(j*j) == 0) {
                    dp[i] = std::min(i/(j*j), dp[i]);
                }
            }
        }
        return dp.back();
    }
};

int main() {
    Solution s;

    std::cout<<s.numSquares(12)<<std::endl;

    return 0;
}
