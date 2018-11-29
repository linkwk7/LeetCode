#include <iostream>
#include <string>
#include <map>

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::map<char, int> contained;
        int maxLength = 0;

        int left = 0;
        for (int right=0,sz=s.size(); right<sz; right++) {
            if (contained.find(s[right]) != contained.end()) {
                left = std::max(left, contained[s[right]]+1);
            }
            contained[s[right]] = right;

            maxLength = std::max(maxLength, right-left+1);
        }

        return maxLength;
    }
};

int main() {
    Solution s;

    std::cout<<s.lengthOfLongestSubstring("dvdf")<<std::endl;

    return 0;
}
