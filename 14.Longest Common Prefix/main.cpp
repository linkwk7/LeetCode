#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        int current=0;
        int minLen = strs[0].size();
        for (int i=1,sz=strs.size(); i<sz; i++) {
            minLen = std::min(minLen, static_cast<int>(strs[i].size()));
        }

        for (; current<minLen; current++) {
            char c = strs[0][current];
            for (int i=1,sz=strs.size(); i<sz; i++) {
                if (strs[i][current] != c) {
                    return strs[0].substr(0, current);
                }
            }
        }
        return strs[0].substr(0, current);
    }
};

int main() {
    Solution s;

    std::vector<std::string> data {
        "flower","flow","flight",
    };
    std::cout<<s.longestCommonPrefix(data);

    return 0;
}
