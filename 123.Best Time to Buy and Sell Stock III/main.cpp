#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::vector<int> profitPrev(prices.size(), 0);
        std::vector<int> profitAft(prices.size(), 0);

        int maxProfitPrev = 0;
        int currentProfitPrev = 0;
        int minProfitAft = 0;
        int currentProfitAft = 0;
        for (int i=1,sz=prices.size(); i<sz; i++) {
            currentProfitPrev += prices[i]-prices[i-1];
            maxProfitPrev = std::max(maxProfitPrev, currentProfitPrev);
            currentProfitPrev = std::max(currentProfitPrev, 0);
            profitPrev[i] = maxProfitPrev;

            currentProfitAft += prices[sz-1-i]-prices[sz-i];
            minProfitAft = std::min(minProfitAft, currentProfitAft);
            currentProfitAft = std::min(currentProfitAft, 0);
            profitAft[sz-1-i] = minProfitAft;
        }

        int maxProfit = 0;
        for (int i=0; i<prices.size(); i++) {
            maxProfit = std::max(maxProfit, profitPrev[i]-profitAft[i]);
        }
        return maxProfit;
    }
};

int main() {
    Solution s;

    std::vector<int> data {7,6,4,3,1};

    std::cout<<s.maxProfit(data)<<std::endl;

    return 0;
}
