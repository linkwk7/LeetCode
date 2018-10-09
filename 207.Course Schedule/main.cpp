#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using std::vector;
using std::pair;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        std::vector<int> indgree(numCourses, 0);

        for (auto elem : prerequisites) {
            indgree[elem.first]++;
        }

        std::vector<int> starts;
        for (int i=0; i<indgree.size(); i++) {
            if (indgree[i] == 0) {
                starts.push_back(i);
            }
        }

        std::unordered_map<int,std::vector<int>> edges;
        for (auto elem : prerequisites) {
            edges[elem.second].push_back(elem.first);
        }

        int count = starts.size();
        for (; !starts.empty(); ) {
            int current = starts.back();
            starts.pop_back();

            for (int next : edges[current]) {
                indgree[next]--;

                if (indgree[next] == 0) {
                    count++;
                    starts.push_back(next);
                }
            }
        }
        return count == numCourses;
    }
};

int main() {
    std::vector<std::pair<int,int>> data {
        {1,0}
    };

    Solution s;
    std::cout<<s.canFinish(2, data)<<std::endl;

    return 0;
}
