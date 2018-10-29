#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        std::vector<int> visited(M.size(), false);

        int count = 0;
        for (int i=0,sz=M.size(); i<sz; i++) {
            if (visited[i] == false) {
                count++;
                dfs(M, visited, i);
            }
        }
        return count;
    }

    void dfs(const std::vector<std::vector<int>> & M, std::vector<int> & visited, int origin) {
        for (int i=0,sz=M.size(); i<sz; i++) {
            if (M[origin][i] != 0 && !visited[i]) {
                visited[i] = true;
                dfs(M, visited, i);
            }
        }
    }
};

int main() {

}