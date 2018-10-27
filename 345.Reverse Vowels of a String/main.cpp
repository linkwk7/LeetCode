#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }

    string reverseVowels(string s) {
        int first = 0;
        int last = s.size()-1;

        for (; first<last; first++,last--) {
            for (; first<last && !isVowel(s[first]); first++);
            for (; first<last && !isVowel(s[last]); last--);
        
            std::swap(s[first], s[last]);
        }

        return s;
    }
};

int main() {
    Solution s;

    std::cout<<s.reverseVowels("leetcode");

    return 0;
}