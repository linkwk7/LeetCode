#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        combinationSum3Aux(result, path, 1, k, n);
        return result;
    }

    void combinationSum3Aux(std::vector<std::vector<int>> & result, std::vector<int> & path, int current, int remain, int target) {
        if (target == 0 && remain == 0) {
            result.push_back(path);
        } else if (target >= current) {
            if (remain == 0) {
                return;
            }
            if (current <= 9) {
                combinationSum3Aux(result, path, current+1, remain, target);
                path.push_back(current);
                combinationSum3Aux(result, path, current+1, remain-1, target-current);
                path.pop_back();
            }
        }
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> result = s.combinationSum3(3,7);

    for (auto elem : result) {
        for (int e : elem) {
            std::cout<<e<<",";
        }
        std::cout<<std::endl;
    }

    return 0;
}
