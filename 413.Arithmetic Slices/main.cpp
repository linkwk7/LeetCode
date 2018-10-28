#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int na = 1;
        int count = 0;
        for (int i=1,sz=A.size(); i<sz; i++) {
            if (na >= 2) {
                if ((A[i]-A[i-1])==(A[i-1]-A[i-2])) {
                    na++;
                    count += na-2;
                } else {
                    na = 2;
                }
            } else {
                na++;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    std::vector<int> data {1,2,3,4};

    std::cout<<s.numberOfArithmeticSlices(data)<<std::endl;

    return 0;
}
