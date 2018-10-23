#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::string;

class Solution {
public:
    int minDistance(string word1, string word2) {
        std::vector<int> last(word2.size()+1, 0);
        std::vector<int> current(word2.size()+1, 0);
        for (int i=0,sz=word2.size(); i<=sz; i++) {
            last[i] = i;
        }

        for (int i=1,sz1=word1.size(),sz2=word2.size(); i<=sz1; i++) {
            current[0] = i;
            for (int j=1; j<=sz2; j++) {
                int inc = (word1[i-1] == word2[j-1] ? 0:1);
                current[j] = std::min({inc+last[j-1], 1+current[j-1], 1+last[j]});
            }
            last = current;
        }

        return last[word2.size()];
    }
};

int main() {
    Solution s;
    
    std::cout<<s.minDistance("horse","ros");

    return 0;
}