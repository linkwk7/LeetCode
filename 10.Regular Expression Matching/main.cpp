#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    // bool isMatch(string s, string p) {
    //     return isMatchAux(s, 0, p, 0);
    // }

    // bool isMatchAux(const std::string & s, int ss, const std::string & p, int ps) {
    //     if (ps == p.size()) {
    //         return ss==s.size();
    //     }

    //     if (p[ps+1] == '*') {
    //         return isMatchAux(s, ss, p, ps+2) || (ss!=s.size() && match(s[ss], p[ps]) && isMatchAux(s, ss+1, p, ps));
    //     }
    //     return ss!=s.size() && match(s[ss], p[ps]) && isMatchAux(s, ss+1, p, ps+1);
    // }

    bool isMatch(string s, string p) {
        std::vector<std::vector<bool>> dp(s.size()+1, std::vector<bool>(p.size()+1, false));
        dp[0][0] = true;

        for (int i=1,sz=p.size(); i<=sz; i++) {
            dp[0][i] = i>1 && p[i-1]=='*' && dp[0][i-2];
        }

        for (int i=1,ssz=s.size(); i<=ssz; i++) {
            for (int j=1,psz=p.size(); j<=psz; j++) {
                if (p[j-1] != '*') {
                    dp[i][j] = dp[i-1][j-1] && match(s[i-1], p[j-1]);
                } else {
                    dp[i][j] = dp[i][j-2] || (match(s[i-1], p[j-2]) && dp[i-1][j]);
                }
            }
        }

        return dp.back().back();
    }

    bool match(char lhs, char rhs) {
        return lhs==rhs || rhs=='.';
    }
};

int main() {
    Solution s;

    std::cout<<s.isMatch("ab",".*c");

    return 0;
}
