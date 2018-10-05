#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        std::vector<std::vector<int>> common(A.size(), std::vector<int>(B.size(), 0));

        int max = 0;
        for (int a=0,asz=A.size(); a<asz; a++) {
            for (int b=0,bsz=B.size(); b<bsz; b++) {
                if (A[a] == B[b]) {
                    common[a][b] = (a<1 || b<1 ? 0:common[a-1][b-1])+1;
                    max =std::max(common[a][b], max);
                }
            }
        }
        return max;
    }
};

int main() {
    std::vector<int> lhs {
        0,1,1,1,1
    };
    std::vector<int> rhs {
        1,0,1,0,1
    };

    Solution s;
    std::cout<<s.findLength(lhs, rhs)<<std::endl;

    return 0;
}
