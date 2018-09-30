#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        std::vector<int> lastRow(n);
        std::vector<int> currentRow(n);

        currentRow.back() = (obstacleGrid[m-1][n-1] == 1? 0:1);

        for (int y=m-1; y>=0; y--) {
            for (int x=n-1; x>=0; x--) {
                if (y == m-1 && x==n-1) {
                    continue;
                }

                if (obstacleGrid[y][x] == 1) {
                    currentRow[x] = 0;
                    continue;
                }

                int count = 0;
                if (x+1 < n && obstacleGrid[y][x+1]==0) {
                    count += currentRow[x+1];
                }
                if (y+1 < m && obstacleGrid[y+1][x]==0) {
                    count += lastRow[x];
                }
                currentRow[x] = count;
            }
            lastRow = currentRow;
        }

        return currentRow[0];
    }
};

int main() {
    std::vector<std::vector<int>> data {
        {0,0},
    };

    Solution s;
    std::cout<<s.uniquePathsWithObstacles(data)<<std::endl;

    return 0;
}
