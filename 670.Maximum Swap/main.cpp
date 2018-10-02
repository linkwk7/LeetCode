#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

class Solution {
public:
    int maximumSwap(int num) {
        std::string numStr = std::to_string(num);
        
        std::vector<int> mapping (10, 0);

        for (int i=0,sz=numStr.size(); i<sz; i++) {
            mapping[numStr[i]-'0']++;
        }

        int max = 9;
        for (int i=0,sz=numStr.size(); i<sz; i++) {
            for (; mapping[max]==0; max--);

            if (numStr[i]-'0' == max) {
                mapping[max]--;
                for (; mapping[max]==0; max--);
            } else {
                for (int ind=sz-1; ind>=0; ind--) {
                    if (numStr[ind]==max+'0') {
                        std::swap(numStr[ind],numStr[i]);
                        break;
                    }
                }
                break;
            }
        }

        int n = 0;
        for (int i=0,sz=numStr.size(); i<sz; i++) {
            n = n*10 + numStr[i]-'0';
        }

        return n;
    }
};

int main() {
    Solution s;
    std::cout<<s.maximumSwap(2736)<<std::endl;

    return 0;
}
