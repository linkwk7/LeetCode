#include <iostream>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int y=0; y<n/2; y++) {
            for (int x=y; x<n-1-y; x++) {
                int first = matrix[y][x];
                matrix[y][x] = matrix[n-x-1][y];
                matrix[n-x-1][y] = matrix[n-y-1][n-x-1];
                matrix[n-y-1][n-x-1] = matrix[x][n-y-1];
                matrix[x][n-y-1] = first;
            }
        }
    }
};

int main() {

}