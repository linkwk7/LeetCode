#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
    int numTrees(int n) {
        std::vector<int> dp(n+1, 0);

        dp[0] = 1;

        for (int i=1; i<=n; i++) {
            for (int j=0; j<i; j++) {
                dp[i] += dp[j]*dp[i-1-j];
            }
        }

        return dp.back();
    }
};

int main() {
    Solution s;
    std::cout<<s.numTrees(3)<<std::endl;

    return 0;
}
