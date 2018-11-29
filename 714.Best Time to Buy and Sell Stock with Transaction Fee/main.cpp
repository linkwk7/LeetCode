#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        std::vector<int> buy(prices.size(), 0);
        std::vector<int> sell(prices.size(), 0);

        buy[0] = -prices[0]-fee;
        sell[0] = 0;
        for (int i=1,sz=prices.size(); i<sz; i++) {
            buy[i] = std::max(buy[i-1], sell[i-1]-prices[i]-fee);
            sell[i] = std::max(sell[i-1], buy[i-1]+prices[i]);
        }

        return sell.back();
    }
};

int main() {
    Solution s;

    std::vector<int> data {1, 3, 2, 8, 4, 9};

    std::cout<<s.maxProfit(data, 2);

    return 0;
}