#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));
        int max = 0;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = std::min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]})+1;
                    max = std::max(max, dp[i][j]);
                }
            }
        }

        return max*max;
    }
};

int main() {
    
}