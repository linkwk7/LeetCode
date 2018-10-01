#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        std::vector<int> currentRow(triangle[height-1].begin(),triangle[height-1].end());
        std::vector<int> lastRow(triangle[height-1].begin(), triangle[height-1].end());

        for (int y=height-2; y>=0; y--) {
            for (int x=0; x<=y; x++) {
                int min = (lastRow[x]<lastRow[x+1] ? lastRow[x]:lastRow[x+1]);
                currentRow[x] = triangle[y][x]+min;
            }
            lastRow = currentRow;
        }

        return currentRow[0];
    }
};

int main() {
    std::vector<std::vector<int>> data {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3},
    };
    Solution s;
    std::cout<<s.minimumTotal(data)<<std::endl;

    return 0;
}
