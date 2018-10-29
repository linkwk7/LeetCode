#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    int numSquares(int n) {
        std::vector<int> dp(n+1, 1000000000);

        dp[0] = 0;
        for (int i=0,end=static_cast<int>(std::sqrt(n)); i<=end; i++) {
            for (int k=i*i; k<=n; k++) {
                dp[k] = std::min(dp[k], dp[k-i*i]+1);
            }
        }

        return dp.back();
    }
};

int main() {
    Solution s;

    std::cout<<s.numSquares(13)<<std::endl;

    return 0;
}
