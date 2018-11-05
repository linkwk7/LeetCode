#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::vector;
using std::pair;

class compPair {
public:
    bool operator() (const std::pair<int,int> & lhs, const std::pair<int,int> & rhs) {
        return lhs.first<rhs.first || (lhs.first==rhs.first && lhs.second<rhs.second);
    }
};

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        std::sort(people.begin(), people.end(), compPair{});

        std::vector<std::pair<int,int>> result(people.size(), std::make_pair(-1, -1));

        for (int i=0,sz=people.size(); i<sz; i++) {
            int index = 0;
            for (int count = people[i].second; count != 0 && index < sz; index++) {
                if (result[index].first >= people[i].first || result[index].first == -1) {
                    count--;
                }
            }
            for (; result[index].first!=-1; index++) {}
            result[index] = people[i];
        }

        return result;
    }
};

int main() {
    Solution s;

    std::vector<std::pair<int,int>> data {
        {7,0},{4,4},{7,1},{5,0},{6,1},{5,2}
    };

    auto result = s.reconstructQueue(data);
    for (auto elem : result) {
        std::cout<<"["<<elem.first<<","<<elem.second<<"]";
    }

    return 0;
}
