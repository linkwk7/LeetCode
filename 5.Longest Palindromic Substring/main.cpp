#include <iostream>
#include <string>
#include <algorithm>

using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }

        int maxLen = 0;
        int maxL = -1;
        for (int i=0,sz=s.size(); i<sz; i++) {
            int len = 0;
            longestPalindromeAux(s, i, i, &len);
            if ((len-1)*2+1 > maxLen) {
                maxLen = (len-1)*2+1;
                maxL = i-len+1;
            }
            longestPalindromeAux(s, i, i+1, &len);
            if (len*2 > maxLen) {
                maxLen = len*2;
                maxL = i-len+1;
            }
        }
        return s.substr(maxL, maxLen);
    }

    void longestPalindromeAux(const std::string & s, int beginL, int beginR, int * len) {
        *len = 0;
        for (; beginL>=0 && beginR<s.length() && s[beginL]==s[beginR]; beginL--,beginR++,(*len)++) {}
    }
};

int main() {
    Solution s;

    std::cout<<s.longestPalindrome("babad")<<std::endl;

    return 0;
}
