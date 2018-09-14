#include <iostream>
#include <string>
#include <vector>
#include <set>

using std::string;
using std::vector;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::vector<std::set<char>>> grids;
        for (int i=0; i<3; i++) {
            grids.push_back(std::vector<std::set<char>>());
            for (int j=0; j<3; j++) {
                grids[i].push_back(std::set<char>());
            }
        }

        for (int i=0; i<9; i++) {
            std::set<char> row;
            std::set<char> column;
            
            for (int j=0; j<9; j++) {
                if (board[i][j] != '.' && row.find(board[i][j]) != row.end()) {
                    return false;
                }

                if (board[i][j] != '.' && column.find(board[j][i]) != column.end()) {
                    return false;
                }

                if (board[i][j] != '.' && grids[i/3][j/3].find(board[i][j]) != grids[i/3][j/3].end()) {
                    return false;
                }

                row.insert(board[i][j]);
                column.insert(board[j][i]);
                grids[i/3][j/3].insert(board[i][j]);
            }
        }
        return true;
    }
};

int main() {

}