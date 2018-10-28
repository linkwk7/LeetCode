#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::vector;

bool compPair (const std::vector<int> & lhs, const std::vector<int> & rhs) {
    return lhs[0]<rhs[0] || (lhs[0]==rhs[0] && lhs[1]<rhs[1]);
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), compPair);

        std::vector<int> dp (pairs.size(), 1);

        int maxLen = 1;
        for (int i=0; i<pairs.size(); i++) {
            for (int j=0; j<i; j++) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = std::max(dp[i], dp[j]+1);
                    maxLen = std::max(maxLen, dp[i]);
                }
            }
        }

        return maxLen;
    }
};

int main() {
    Solution s;

    std::vector<std::vector<int>> data {{1,2}, {2,3}, {3,4}};

    std::cout<<s.findLongestChain(data);

    return 0;
}
