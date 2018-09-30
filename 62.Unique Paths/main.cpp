#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> result;

        for (int i=0; i<m; i++) {
            result.push_back(std::vector<int>(n, 0));
        }
        result[m-1][n-1] = 1;

        for (int y=m-1; y>=0; y--) {
            for (int x=n-1; x>=0; x--) {
                if (y == m-1 && x==n-1) {
                    continue;
                }

                int count = 0;
                if (x+1<n) {
                    count += result[y][x+1];
                }
                if (y+1<m) {
                    count += result[y+1][x];
                }
                result[y][x] = count;
            }
        }

        return result[0][0];
    }
};

int main() {
    Solution s;

    std::cout<<s.uniquePaths(7,3)<<std::endl;

    return 0;
}
