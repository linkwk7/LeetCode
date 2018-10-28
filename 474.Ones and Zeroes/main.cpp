#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        std::vector<std::vector<int>> last;
        std::vector<std::vector<int>> current;
        for (int i=0; i<=m; i++) {
            last.push_back(std::vector<int>(n+1, 0));
            current.push_back(std::vector<int>(n+1, 0));
        }

        for (int i=0,sz=strs.size(); i<sz; i++) {
            int zc = std::count(strs[i].begin(), strs[i].end(), '0');
            int oc = strs[i].size()-zc;

            for (int y=zc; y<=m; y++) {
                for (int x=oc; x<=n; x++) {
                    current[y][x] = std::max(last[y-zc][x-oc]+1, last[y][x]);
                }
            }

            last = current;
        }

        return current[m][n];
    }
};

int main() {
    Solution s;

    std::vector<std::string> data {"10", "0001", "111001", "1", "0"};

    std::cout<<s.findMaxForm(data, 5,3);

    return 0;
}
