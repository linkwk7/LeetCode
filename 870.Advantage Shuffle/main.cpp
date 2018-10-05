#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        std::multiset<int> nums(A.begin(),A.end());

        for (int i=0,sz=B.size(); i<sz; i++) {
            auto iter = (*nums.rbegin()<=B[i] ? nums.begin():nums.upper_bound(B[i]));

            A[i] = *iter;
            nums.erase(iter);
        }
        return A;
    }
};

int main() {
    std::vector<int> lhs {2,7,11,15};
    std::vector<int> rhs {1,10,4,11};

    Solution s;
    s.advantageCount(lhs, rhs);
    std::for_each(lhs.begin(),lhs.end(), [](int arg) {
        std::cout<<arg<<" ";
    });
    std::cout<<std::endl;

    return 0;
}
