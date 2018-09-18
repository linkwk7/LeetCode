#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::string;

struct element {
    element(char c, int f):ch(c), freq(f) {}

    char ch;
    int freq;
};

bool compareElement(const element & lhs, const element & rhs) {
    return lhs.freq > rhs.freq;
}

class Solution {
public:
    string frequencySort(string s) {
        std::unordered_map<char, int> frequencyMap;

        for (auto iter=s.begin(); iter!=s.end(); iter++) {
            frequencyMap[*iter]++;
        }

        std::vector<element> elementList;
        for (auto iter=frequencyMap.begin(); iter!=frequencyMap.end(); iter++) {
            elementList.push_back(element(iter->first, iter->second));
        }

        std::sort(elementList.begin(), elementList.end(), compareElement);

        for (int index=0, elementIndex=0; elementIndex<elementList.size(); elementIndex++) {
            for (int i=0; i<elementList[elementIndex].freq; i++,index++) {
                s[index] = elementList[elementIndex].ch;
            }
        }

        return s;
    }
};

int main() {
    Solution s;
    std::cout<<s.frequencySort("tree");

    return 0;
}
