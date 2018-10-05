#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int max = A[0];
        for (int i=2,sz=A.size(); i<sz; i++) {
            max = (max>A[i-2] ? max:A[i-2]);
            if (max > A[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::vector<int> data {
        1,2,0
    };

    Solution s;
    std::cout<<s.isIdealPermutation(data)<<std::endl;

    return 0;
}
