#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        std::string longest;
        for (int i=0,sz=d.size(); i<sz; i++) {
            if (findLongestWordAux(s, d[i])) {
                if (d[i].size() > longest.size() || (d[i].size() == longest.size() && d[i]<longest)) {
                    longest = d[i];
                }
            }
        }
        return longest;
    }

    bool findLongestWordAux(const std::string & s, const std::string word) {
        int l = 0;
        int r = 0;

        for (; l<s.size(); l++) {
            if (s[l] == word[r]) {
                r++;
                if (r == word.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;

    std::vector<std::string> data {"ale","apple","monkey","plea"};
    std::cout<<s.findLongestWord("abpcplea", data);

    return 0;
}