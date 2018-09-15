#include <deque>
#include <deque>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using std::vector;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::vector<int> counts(26, 0);
        for (auto iter=tasks.begin(); iter!=tasks.end(); iter++) {
            counts[*iter-'A']++;
        }

        std::sort(counts.begin(), counts.end());

        int maxCount = 1;
        for (int i=24; i>=0 && counts[i]==counts[25]; i--) {
            maxCount++;
        }

        int empty = (counts[25]-1)*(n-maxCount+1);
        int available = tasks.size() - counts[25]*maxCount;
        int idles = (empty-available>0 ? empty-available:0);
        return tasks.size() + idles;
    }
};

int main() {
    std::vector<char> data {'A','A','B','B','C','C'};

    Solution s;
    std::cout<<s.leastInterval(data, 1);

    return 0;
}
