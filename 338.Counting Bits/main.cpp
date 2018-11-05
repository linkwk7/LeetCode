#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> result(num+1, 0);

        if (num == 0) {
            return result;
        }

        result[1] = 1;
        for (int i=2; i<=num; i++) {
            int diff = (i^(i-1))>>1;
            result[i] = result[i-1]-result[diff]+1;
        }
        return result;
    }
};

int main() {
    Solution s;

    auto res = s.countBits(5);

    for (int elem : res) {
        std::cout<<elem<<",";
    }

    return 0;
}