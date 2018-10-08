#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<bool> contained(s.size()+1, false);
        contained[0] = true;

        for (int i=1; i<=s.size(); i++) {
            for (int j=0; j<i; j++) {
                if (contained[j] && std::find(wordDict.begin(),wordDict.end(),s.substr(j, i-j)) != wordDict.end()) {
                    contained[i] = true;
                    break;
                }
            }
        }

        return contained.back();
    }
};

int main() {
    std::vector<std::string> data {"leet","code"};
    Solution s;
    std::cout<<s.wordBreak("leetcode", data)<<std::endl;

    return 0;
}
