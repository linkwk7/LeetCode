#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount+1, 100000000);
        dp[0] = 0;

        for (int value : coins) {
            for (int i=value; i<=amount; i++) {
                dp[i] = std::min(dp[i], dp[i-value]+1);
            }
        }
        return dp[amount]>=100000000 ? -1:dp[amount];
    }
};

int main() {
    Solution s;
    std::vector<int> data {2};
    std::cout<<s.coinChange(data, 3);

    return 0;
}
