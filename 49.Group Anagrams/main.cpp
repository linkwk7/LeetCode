#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::string, std::vector<std::string>> rstMap;

        for (int i=0, sz=strs.size(); i<sz; i++) {
            std::string str = strs[i];
            std::sort(str.begin(), str.end());

            auto iter = rstMap.find(str);
            if (iter != rstMap.end()) {
                iter->second.push_back(strs[i]);
            } else {
                rstMap[str] = std::vector<std::string> ();
                rstMap[str].push_back(strs[i]);
            }
        }

        std::vector<std::vector<string>> result;
        for (auto iter=rstMap.begin(); iter!=rstMap.end(); iter++) {
            result.push_back(iter->second);
        }
        return result;
    }
};

int main() {
    std::vector<std::string> data {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution s;
    std::vector<std::vector<std::string>> result = s.groupAnagrams(data);

    std::for_each(result.begin(), result.end(), [](const std::vector<std::string> & args) {
        std::for_each(args.begin(), args.end(), [](const std::string & str) {
            std::cout<<str<<",";
        });
        std::cout<<std::endl;
    });

    return 0;
}
