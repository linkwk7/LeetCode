#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x^y;
        if (diff != 0) {
            int count = 0;
            for (; diff!=0; count++) {
                diff = diff&(diff-1);
            }
            return count;
        }
        return 0;
    }
};

int main() {
    Solution s;

    std::cout<<s.hammingDistance(1,4);

    return 0;
}