#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        std::vector<int> leftLen(A.size());
        std::vector<int> rightLen(A.size());

        for (int i=0,sz=A.size(); i<sz; i++) {
            int len = 0;
            for (int j=i-1; j>=0&&A[i]<=A[j]; j--) {
                len++;
            }
            leftLen[i] = len+1;
        }
        for (int i=A.size()-1,sz=A.size(); i>=0; i--) {
            int len = 0;
            for (int j=i+1; j<sz&&A[i]<A[j]; j++) {
                len++;
            }
            rightLen[i] = len+1;
        }

        int count = 0;
        for (int i=0,sz=A.size(); i<sz; i++) {
            count += leftLen[i]*rightLen[i]*A[i];
            count = count%1000000007;
        }

        return count;
    }
};

int main() {
    std::vector<int> data {
        71,55,82,55
    };

    Solution s;
    std::cout<<s.sumSubarrayMins(data)<<std::endl;

    return 0;
}
