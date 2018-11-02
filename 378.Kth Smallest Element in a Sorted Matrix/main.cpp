#include <iostream>
#include <vector>
#include <queue>

using std::vector;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        std::priority_queue<int> pq;

        for (int y=0; y<n; y++) {
            for (int x=0; x<n; x++) {
                if (pq.size() < k) {
                    pq.push(matrix[y][x]);
                } else {
                    if (matrix[y][x]<pq.top()) {
                        pq.pop();
                        pq.push(matrix[y][x]);
                    }
                }
            }
        }
        return pq.top();
    }
};

int main() {
    Solution s;

    std::vector<std::vector<int>> data {
        {1, 3, 5}, {6, 7, 12}, {11, 14, 14},
    };
    std::cout<<s.kthSmallest(data, 5);

    return 0;
}
