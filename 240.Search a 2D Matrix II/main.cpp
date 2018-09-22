#include <iostream>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }

        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }

        int x = 0;
        int y = m-1;

        for (; true; ) {
            if (x < 0 || y<0 || x==n || y==m) {
                return false;
            }

            if (matrix[y][x] == target) {
                return true;
            } else if (matrix[y][x] > target) {
                y--;
            } else {
                x++;
            }
        }
        return false;
    }
};

int main() {
    std::vector<std::vector<int>> data = {{1,   4,  7, 11, 15}, {2,   5,  8, 12, 19}, {3,   6,  9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};

    Solution s;
    std::cout<<s.searchMatrix(data, 5)<<std::endl;

    return 0;
}