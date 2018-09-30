#include <iostream>
#include <map>

class Solution {
public:
    int numTrees(int n) {
        std::map<std::pair<int,int>, int> tmp;

        return numTreesRange(tmp, 1, n+1);
    }

    int numTreesRange(std::map<std::pair<int,int>, int> & res, int first, int last) {
        auto iter = res.find(std::make_pair(first,last));
        if (iter != res.end()) {
            return iter->second;
        }

        if (last - first <= 1) {
            res[std::make_pair(first,last)] = 1;
            return 1;
        }

        int count = 0;
        for (int i=first; i<last; i++) {
            count += numTreesRange(res, first, i)*numTreesRange(res, i+1, last);
        }
        res[std::make_pair(first,last)] = count;
        return count;
    }
};

int main() {
    Solution s;
    std::cout<<s.numTrees(3)<<std::endl;

    return 0;
}
