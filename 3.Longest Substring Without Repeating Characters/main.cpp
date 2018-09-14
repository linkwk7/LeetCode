#include <iostream>
#include <string>
#include <set>

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> contained;
        int maxLength = 0;
        int head = 0;
        int current = 0;

        for (int len=s.size(); current<len; current++) {
            if (contained.find(s[current]) != contained.end()) {
                int currentLen = current-head;
                if (currentLen > maxLength) {
                    maxLength = currentLen;
                }

                for (; head<current; head++) {
                    contained.erase(s[head]);
                    if (s[head] == s[current]) {
                        head++;
                        break;
                    }
                }

                contained.insert(s[current]);
            } else {
                contained.insert(s[current]);
            }
        }
        if (current - head > maxLength) {
            maxLength = current-head;
        }

        return maxLength;
    }
};

int main() {
    Solution s;

    std::cout<<s.lengthOfLongestSubstring("dvdf")<<std::endl;

    return 0;
}
