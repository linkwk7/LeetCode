#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using std::vector;

class compPair {
public:
    bool operator() (const std::pair<int,int> & lhs, const std::pair<int,int> & rhs) const {
        return lhs.second > rhs.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency;
        for (int elem : nums) {
            frequency[elem]++;
        }

        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, compPair> topk;
        for (auto elem : frequency) {
            if (topk.size() < k) {
                topk.push(elem);
            } else {
                if (topk.top().second < elem.second) {
                    topk.pop();
                    topk.push(elem);
                }
            }
        }
        std::vector<int> result;
        for (; !topk.empty(); topk.pop()) {
            result.push_back(topk.top().first);
        }
        return result;
    }
};

int main() {
    Solution s;
    std::vector<int> data {1,1,1,2,2,3};
    std::vector<int> res = s.topKFrequent(data, 2);

    for (int elem : res) {
        std::cout<<elem<<",";
    }

    return 0;
}
