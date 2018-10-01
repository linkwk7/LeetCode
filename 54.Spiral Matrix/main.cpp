#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> result;

        int m = matrix.size();
        if (m == 0) {
            return result;
        }
        int n = matrix[0].size();

        int min = std::min(m,n);
        int round = (min%2==0 ? min/2:min/2+1);

        m--;
        n--;
        for (int i=0; i<round; i++) {
            int x = i;
            int y = i;

            if (m == 0) {
                for (int i=0; i<=n; i++,x++) {
                    result.push_back(matrix[y][x]);
                }
                break;
            }
            if (n == 0) {
                for (int i=0; i<=m; i++,y++) {
                    result.push_back(matrix[y][x]);
                }
                break;
            }

            for (int dir=0; dir<4; dir++) {
                int count = (dir%2==0 ? n:m);
                for (int c=0; c<count; c++) {
                    result.push_back(matrix[y][x]);

                    switch(dir) {
                        case 0:x++;break;
                        case 1:y++;break;
                        case 2:x--;break;
                        case 3:y--;break;
                    }
                }
            }

            m-=2;
            n-=2;
        }

        return result;
    }
};

int main() {
    std::vector<std::vector<int>> data {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    Solution s;
    std::vector<int> result = s.spiralOrder(data);

    std::for_each(result.begin(),result.end(), [](int arg) {
        std::cout<<arg<<" ";
    });
    std::cout<<std::endl;

    return 0;
}
