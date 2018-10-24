#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i=0,sz=s.size(); i<sz; i++) {
            for (int j=0; i-j>=0 && i+j<s.size() && s[i-j] == s[i+j]; j++) {
                count++;
            }
            for (int j=0; i-1-j>=0 && i+j<s.size() && s[i-1-j]==s[i+j]; j++) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    std::cout<<s.countSubstrings("aaa");

    return 0;
}