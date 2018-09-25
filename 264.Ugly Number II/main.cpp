#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> result(n, 1);

        int base2 = 2;
        int base3 = 3;
        int base5 = 5;
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        for (int i=1; i<n; i++) {
            int current = std::min(base2, std::min(base3, base5));

            result[i] = current;

            if (current == base2) {
                base2 = 2*result[++index2];
            }
            if (current == base3) {
                base3 = 3*result[++index3];
            }
            if (current == base5) {
                base5 = 5*result[++index5];
            }
        }

        return result.back();
    }
};

int main() {
    Solution s;
    std::cout<<s.nthUglyNumber(10);

    return 0;
}
