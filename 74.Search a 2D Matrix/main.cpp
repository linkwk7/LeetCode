#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        int first = 0;
        int last = matrix.size()-1;

        for (; first<last; ) {
            int mid = (first+last)/2;

            if (matrix[mid][0] < target) {
                first = mid;
                if (mid+1 < matrix.size()) {
                    if (matrix[mid+1][0] > target) {
                        break;
                    } else {
                        first++;
                    }
                }
            } else if (matrix[mid][0] == target) {
                first = mid;
                break;
            } else {
                last = mid-1;
            }
        }

        std::cout<<first<<std::endl;

        int row = first;
        first = 0;
        last = matrix[row].size() - 1;
        for (; first<=last; ) {
            int mid = (first+last)/2;

            if (matrix[row][mid] < target) {
                first = mid+1;
            } else if (matrix[row][mid] == target) {
                return true;
            } else {
                last = mid-1;
            }
        }
        return false;
    }
};

int main() {
    std::vector<std::vector<int>> data {
        {1},
        {3},
    };

    Solution s;
    std::cout<<s.searchMatrix(data, 3)<<std::endl;

    return 0;
}
