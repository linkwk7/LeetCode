#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        std::vector<std::pair<int,int>> offset {
            {-1,-1}, {-1,0}, {0,-1}, {0,1}, {1,0}, {1,1}, {-1,1}, {1,-1}
        };
        for (int y=0,ysz=board.size(); y<ysz; y++) {
            for (int x=0,xsz=board[0].size(); x<xsz; x++) {
                int count = 0;
                for (int i=0,sz=offset.size(); i<sz; i++) {
                    int nx = x+offset[i].first;
                    int ny = y+offset[i].second;
                    if (nx < 0 || nx >= xsz || ny < 0 || ny >= ysz) {
                        continue;
                    }
                    count += board[ny][nx] & 1;
                }

                if (board[y][x] & 1) {
                    if (count < 2 || count > 3) {
                        board[y][x] &= 1;
                    } else {
                        board[y][x] |= 2;
                    }
                } else {
                    board[y][x] |= (count==3 ? 2:0);
                }
            }
        }
        for (int y=0,ysz=board.size(); y<ysz; y++) {
            for (int x=0,xsz=board[0].size(); x<xsz; x++) {
                board[y][x] = board[y][x]>>1;
            }
        }
    }
};

int main() {
    std::vector<std::vector<int>> data {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0},
    };

    Solution s;
    s.gameOfLife(data);

    std::for_each(data.begin(), data.end(), [](const std::vector<int> & arg) {
        std::for_each(arg.begin(), arg.end(), [](int ar) {
            std::cout<<ar<<" ";
        });
        std::cout<<std::endl;
    });

    return 0;
}
