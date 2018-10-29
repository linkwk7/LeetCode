#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());

        std::vector<std::vector<int>> result;
        std::vector<int> path;
        combinationSumAux(result, path, candidates, 0, target);

        return result;
    }

    void combinationSumAux(std::vector<std::vector<int>> & result, std::vector<int> & path, const std::vector<int> & candidates, int current, int target) {
        if (target == 0) {
            result.push_back(path);
        } else if (target > 0) {
            for (int i=current; i<candidates.size(); i++) {
                if (i>current && candidates[i]==candidates[i-1]) {
                    continue;
                }
                path.push_back(candidates[i]);
                combinationSumAux(result, path, candidates, i+1, target-candidates[i]);
                path.pop_back();
            }
        }
    }
};

int main() {
    std::vector<int> data {10,1,2,7,6,1,5};

    Solution s;
    std::vector<std::vector<int>> result = s.combinationSum(data, 8);

    std::for_each(result.begin(),result.end(), [](const std::vector<int> & arg) {
        std::for_each(arg.begin(),arg.end(), [](int num) {
            std::cout<<num<<",";
        });
        std::cout<<std::endl;
    });
}
