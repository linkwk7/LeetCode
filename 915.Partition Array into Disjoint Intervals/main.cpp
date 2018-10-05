#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        std::vector<std::pair<int,int>> nums(A.size());

        int currentMax = A[0];
        for (int i=0,sz=A.size(); i<sz; i++) {
            currentMax = std::max(currentMax, A[i]);
            nums[i].first = currentMax;
        }
        int currentMin = A.back();
        for (int i=A.size()-1; i>=0; i--) {
            currentMin = std::min(currentMin, A[i]);
            nums[i].second = currentMin;
        }

        for (int i=1,sz=A.size(); i<sz; i++) {
            if (nums[i-1].first<=nums[i].second) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    std::vector<int> data {5,0,3,8,6};
    Solution s;
    std::cout<<s.partitionDisjoint(data)<<std::endl;

    return 0;
}
