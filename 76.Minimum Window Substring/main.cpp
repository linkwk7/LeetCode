#include <iostream>
#include <unordered_map>
#include <string>

using std::string;

class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char,int> target;

        for (int i=0,sz=t.size(); i<sz; i++) {
            target[t[i]]++;
        }

        int slow = 0;
        int fast = 0;
        int targetCount = target.size();
        int minSlow = 0;
        int minFast = 0;

        for (; true; ) {
            for (int sz=s.size(); fast<sz; ) {
                auto iter = target.find(s[fast]);
                fast++;
                if (iter != target.end()) {
                    iter->second--;
                    if (iter->second == 0) {
                        targetCount--;
                        if (targetCount == 0) {
                            break;
                        }
                    }
                }
            }

            if (targetCount != 0) {
                break;
            }

            for (; slow<fast; ) {
                auto iter = target.find(s[slow]);
                slow++;
                if (iter != target.end()) {
                    iter->second++;
                    if (iter->second == 1) {
                        targetCount++;
                        break;
                    }
                }
            }

            if ((fast-slow) < (minFast-minSlow) || minFast==minSlow) {
                minSlow = slow-1;
                minFast = fast;
            }
        }

        return s.substr(minSlow, minFast-minSlow);
    }
};

int main() {
    Solution s;

    std::cout<<s.minWindow("ADOBECODEBANC","ABC");

    return 0;
}
