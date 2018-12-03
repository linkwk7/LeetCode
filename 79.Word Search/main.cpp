#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        std::vector<std::vector<bool>> seen(board.size(), std::vector<bool>(board[0].size(), false));

        for (int row=0,sz=board.size(); row<sz; row++) {
            for (int column=0,s=board[0].size(); column<s; column++) {
                if (existAux(board, seen, column, row, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool existAux(std::vector<std::vector<char>> & board, std::vector<std::vector<bool>> & seen, int x, int y, 
        const std::string & word, int pos) {
        if (y < 0 || y >= board.size() || x < 0 || x >= board[0].size()) {
            return false;
        }

        if (seen[y][x] == true) {
            return false;
        }

        int offset[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        if (board[y][x] == word[pos]) {
            seen[y][x] = true;

            if (pos+1 == word.size()) {
                return true;
            }

            for (int i=0; i<4; i++) {
                if (existAux(board, seen, x+offset[i][0], y+offset[i][1], word, pos+1)) {
                    return true;
                }
            }

            seen[y][x] = false;
        }
        return false;
    }
};

int main() {
    Solution s;

    std::vector<std::vector<char>> data {
        {
            'A',
        },
    };

    std::cout<<s.exist(data, "A")<<std::endl;
    std::cout<<s.exist(data, "SEE")<<std::endl;
    std::cout<<s.exist(data, "ABCB")<<std::endl;

    return 0;
}
