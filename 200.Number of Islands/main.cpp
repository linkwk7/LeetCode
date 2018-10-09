#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int row=0; row<grid.size(); row++) {
            for (int column=0; column<grid[row].size(); column++) {
                if (grid[row][column] != '0') {
                    count++;
                    clearIsland(grid, row, column);
                }
            }
        }
        return count;
    }

    void clearIsland(std::vector<std::vector<char>>& grid, int row, int column) {
        if (row >= 0 && row<grid.size() && column>=0 && column<grid[0].size() && grid[row][column]!='0') {
            grid[row][column] = '0';

            clearIsland(grid, row+1, column);
            clearIsland(grid, row, column+1);
            clearIsland(grid, row-1, column);
            clearIsland(grid, row, column-1);
        }
    }
};

int main() {
    std::vector<std::vector<char>> data {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
    };

    Solution s;
    std::cout<<s.numIslands(data);

    return 0;
}
