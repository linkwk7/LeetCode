#include <iostream>
#include <vector>
#include <utility>

using std::vector;
using std::pair;

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.size() < 1) {
            return std::vector<std::pair<int,int>> ();
        }

        std::vector<std::vector<bool>> toPacific;
        std::vector<std::vector<bool>> toAtlantic;
        for (int i=0; i<matrix.size(); i++) {
            toPacific.push_back(std::vector<bool>(matrix[0].size(), false));
            toAtlantic.push_back(std::vector<bool>(matrix[0].size(), false));
        }

        int m = matrix.size();
        int n = matrix[0].size();
        for (int i=0; i<m; i++) {
            pacificAtlanticAux(matrix, toPacific, -1, 0, i);
            pacificAtlanticAux(matrix, toAtlantic, -1, n-1, i);
        }
        for (int i=0; i<n; i++) {
            pacificAtlanticAux(matrix, toPacific, -1, i, 0);
            pacificAtlanticAux(matrix, toAtlantic, -1, i, m-1);
        }

        std::vector<std::pair<int,int>> result;
        for (int y=0; y<m; y++) {
            for (int x=0; x<n; x++) {
                if (toPacific[y][x] && toAtlantic[y][x]) {
                    result.push_back(std::pair<int,int>(y, x));
                }
            }
        }
        return result;
    }

    void pacificAtlanticAux(const std::vector<std::vector<int>> & matrix, std::vector<std::vector<bool>> & available, int origin, int x, int y) {
        if (y<0 || y>=available.size() || x<0 || x>=available[0].size()) {
            return;
        }
        if (available[y][x] == true) {
            return;
        }
        if (matrix[y][x] >= origin) {
            available[y][x] = true;
            pacificAtlanticAux(matrix, available, matrix[y][x], x+1, y);
            pacificAtlanticAux(matrix, available, matrix[y][x], x, y+1);
            pacificAtlanticAux(matrix, available, matrix[y][x], x-1, y);
            pacificAtlanticAux(matrix, available, matrix[y][x], x, y-1);
        }
    }
};

int main() {
    std::vector<std::vector<int>> data {
        {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}
    };
    Solution s;
    std::vector<std::pair<int,int>> result = s.pacificAtlantic(data);

    for (auto elem : result) {
        std::cout<<elem.first<<","<<elem.second<<std::endl;
    }

    return 0;
}