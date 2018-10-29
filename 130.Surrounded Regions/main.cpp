#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() < 2) {
            return;
        }

        int m = board.size();
        int n = board[0].size();

        for (int i=0; i<m; i++) {
            solveAux(board, 0, i, 'Z');
            solveAux(board, n-1, i, 'Z');
        }
        for (int i=0; i<n; i++) {
            solveAux(board, i, 0, 'Z');
            solveAux(board, i, m-1, 'Z');
        }

        for (int y=0; y<m; y++) {
            for (int x=0; x<n; x++) {
                if (board[y][x] == 'O') {
                    solveAux(board, x, y, 'X');
                }
            }
        }
        for (int y=0; y<m; y++) {
            for (int x=0; x<n; x++) {
                if (board[y][x] == 'Z') {
                    board[y][x] = 'O';
                }
            }
        }
    }

    void solveAux(std::vector<std::vector<char>> & board, int x, int y, char c) {
        if (y<0 || y>=board.size() || x<0 || x>=board[0].size()) {
            return;
        }
        if (board[y][x] == 'O') {
            board[y][x] = c;

            solveAux(board, x+1, y, c);
            solveAux(board, x, y+1, c);
            solveAux(board, x-1, y, c);
            solveAux(board, x, y-1, c);
        }
    }
};

int main() {

}