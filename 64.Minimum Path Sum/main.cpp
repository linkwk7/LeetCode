#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() < 1) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();

        std::vector<int> lastRow(n);
        std::vector<int> currentRow(n);

        currentRow.back() = grid[m-1][n-1];

        for (int y=m-1; y>=0; y--) {
            for (int x=n-1; x>=0; x--) {
                if (y==m-1 && x==n-1) {
                    continue;
                }

                int min = -1;
                if (x+1 < n) {
                    if (min == -1 || currentRow[x+1]<min) {
                        min = currentRow[x+1];
                    }
                }
                if (y+1 < m) {
                    if (min == -1 || lastRow[x]<min) {
                        min = lastRow[x];
                    }
                }
                currentRow[x] = min+grid[y][x];
            }
            lastRow = currentRow;
        }

        return currentRow[0];
    }
};

int main() {
    std::vector<std::vector<int>> data {
        {1,2,5},
        {3,2,1},
    };

    Solution s;
    std::cout<<s.minPathSum(data)<<std::endl;

    return 0;
}
