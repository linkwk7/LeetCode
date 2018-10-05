#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        int sum = 0;
        int maxProfit = sum;
        for (int i=1,sz=prices.size(); i<sz; i++) {
            sum += prices[i]-prices[i-1];
            maxProfit = std::max(sum, maxProfit);
            sum = (sum<0 ? 0:sum);
        }

        return maxProfit;
    }
};

int main() {
    std::vector<int> data {7,1,5,3,6,4};
    Solution s;

    std::cout<<s.maxProfit(data)<<std::endl;

    return 0;
}