#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    bool validPalindrome(string s) {
        for (int l=0,r=s.size()-1; l<r; l++, r--) {
            if (s[l] != s[r]) {
                return isPalindrome(s, l, r-1) || isPalindrome(s, l+1, r);
            }
        }
        return true;
    }

    bool isPalindrome(const std::string & s, int l, int r) {
        for (; l<r; l++,r--) {
            if (s[l] != s[r]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;

    std::cout<<s.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga")<<std::endl;

    return 0;
}