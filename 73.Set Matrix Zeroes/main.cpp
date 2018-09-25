#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int fRow = -1;
        for (int row=0,sz=matrix.size(); row<sz; row++) {
            for (int column=0,s=matrix[row].size(); column<s; column++) {
                if (matrix[row][column] == 0) {
                    fRow = row;
                    break;
                }
            }
            if (fRow != -1) {
                break;
            }
        }

        if (fRow == -1) {
            return;
        }

        for (int column=0,sz=matrix[0].size(); column<sz; column++) {
            for (int row=0,s=matrix.size(); row<s; row++) {
                if (matrix[row][column] == 0) {
                    matrix[fRow][column] = 0;
                    break;
                }
            }
        }

        // Clear all row
        for (int row=0,sz=matrix.size(); row<sz; row++) {
            if (row != fRow) {
                for (int column=0,s=matrix[row].size(); column<s; column++) {
                    if (matrix[row][column] == 0) {
                        clearRow(matrix, row);
                        break;
                    }
                }
            }
        }

        for (int column=0,sz=matrix[fRow].size(); column<sz; column++) {
            if (matrix[fRow][column] == 0) {
                clearColumn(matrix, column);
            }
        }

        clearRow(matrix, fRow);
    }

    void clearRow(vector<vector<int>>& matrix, int row) {
        for (int i=0,sz=matrix[0].size(); i<sz; i++) {
            matrix[row][i] = 0;
        }
    }

    void clearColumn(vector<vector<int>>& matrix, int column) {
        for (int i=0,sz=matrix.size(); i<sz; i++) {
            matrix[i][column] = 0;
        }
    }
};

int main() {
    std::vector<std::vector<int>> data {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5},
    };

     Solution s;
     s.setZeroes(data);

     std::for_each(data.begin(),data.end(), [](const std::vector<int> & arg) {
         std::for_each(arg.begin(),arg.end(), [](int ar) {
             std::cout<<ar<<" ";
         });
         std::cout<<std::endl;
     });
}
