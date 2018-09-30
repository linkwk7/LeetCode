#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int count = 0;
        for (int i=0,sz=words.size(); i<sz; i++) {
            if (matchingSubSequence(S, words[i])) {
                count++;
            }
        }
        return count;
    }

    bool matchingSubSequence(string S, const std::string & match) {
        int matchIndex = 0;
        for (int sIndex=0,sz=S.size(); sIndex<sz; sIndex++) {
            if (S[sIndex] == match[matchIndex]) {
                matchIndex++;

                if (matchIndex == match.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    std::vector<std::string> words {
        "a", "bb", "acd", "ace",
    };
    Solution s;
    std::cout<<s.numMatchingSubseq("abcde",words)<<std::endl;

    return 0;
}