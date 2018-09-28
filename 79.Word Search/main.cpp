#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        std::vector<std::vector<bool>> seen;
        for (int i=0,sz=board.size(); i<sz; i++) {
            seen.push_back(std::vector<bool>(board[0].size(), false));
        }

        for (int row=0,sz=board.size(); row<sz; row++) {
            for (int column=0,s=board[0].size(); column<s; column++) {
                if (searchRecur(board, seen, column, row, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool searchRecur(std::vector<std::vector<char>> & board, std::vector<std::vector<bool>> & seen, int x,int y,
        const std::string & word, int current) {
        if (seen[y][x] == true) {
            return false;
        }

        if (board[y][x] == word[current]) {
            seen[y][x] = true;

            if (current == word.size()-1) {
                return true;
            }

            if (y >= 1) {
                if (searchRecur(board, seen, x, y-1, word, current+1)) {
                    return true;
                }
            }
            if (y < board.size()-1) {
                if (searchRecur(board, seen, x, y+1, word, current+1)) {
                    return true;
                }
            }
            if (x >= 1) {
                if (searchRecur(board, seen, x-1, y, word, current+1)) {
                    return true;
                }
            }
            if (x < board[0].size()-1) {
                if (searchRecur(board,seen, x+1, y, word, current+1)) {
                    return true;
                }
            }

            seen[y][x] = false;
            return false;
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
