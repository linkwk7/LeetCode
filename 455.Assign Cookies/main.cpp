#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int current = 0;
        int content = 0;
        for (int greedy : g) {
            for (; current<s.size() && s[current]<greedy; current++);

            if (current<s.size()) {
                content++;
                current++;
            } else {
                break;
            }
        }
        return content;
    }
};

int main() {
    std::vector<int> data0 {1,2};
    std::vector<int> data1 {1,2,3};

    Solution s;

    std::cout<<s.findContentChildren(data0, data1);

    return 0;
}
