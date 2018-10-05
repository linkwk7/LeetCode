#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i=1,sz=prices.size(); i<sz; i++) {
            if (prices[i] > prices[i-1]) {
                sum += prices[i]-prices[i-1];
            }
        }
        return sum;
    }
};

int main() {
    std::vector<int> data {7,1,5,3,6,4};

    Solution s;
    std::cout<<s.maxProfit(data)<<std::endl;

    return 0;
}