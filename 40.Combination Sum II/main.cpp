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
        combinationSumUtil(result, path, candidates, target,0);

        return result;
    }

    void combinationSumUtil(std::vector<std::vector<int>> & result, std::vector<int>& path, const vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.push_back(path);
        } else if (target < 0) {
            return;
        } else {
            for (int i=start, sz=candidates.size(); i<sz; i++) {
                if (i > start && candidates[i]==candidates[i-1]) {
                    continue;
                }

                path.push_back(candidates[i]);
                combinationSumUtil(result, path, candidates, target-candidates[i], i+1);
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
