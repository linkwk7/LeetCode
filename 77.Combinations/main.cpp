#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        combineAux(result, path, 1, n, k);
        return result;
    }

    void combineAux(std::vector<std::vector<int>> & result, std::vector<int> & path, int current, int n, int remain) {
        if (remain == 0) {
            result.push_back(path);
        } else {
            if (n - current + 1 >= remain) {
                combineAux(result, path, current+1, n, remain);
                path.push_back(current);
                combineAux(result, path, current+1, n, remain-1);
                path.pop_back();
            }
        }
    }
};

int main() {
    Solution s;
    
    std::vector<std::vector<int>> result = s.combine(4,2);

    for (auto elem : result) {
        for (int e : elem) {
            std::cout<<e<<",";
        }
        std::cout<<std::endl;
    }

    return 0;
}