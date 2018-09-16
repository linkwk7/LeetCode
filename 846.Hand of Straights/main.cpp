#include <iostream>
#include <map>
#include <vector>

using std::vector;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        std::map<int, int> cards;
        for (auto iter=hand.begin(); iter!=hand.end(); iter++) {
            cards[*iter]++;
        }

        for (auto iter=cards.begin(); iter!=cards.end(); iter++) {
            if (iter->second > 0) {
                for (int i=0, num=iter->second; i<W; i++) {
                    cards[iter->first+i] -= num;
                    if (cards[iter->first+i] < 0) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    std::vector<int> data1 {1,2,3,6,2,3,4,7,8};
    std::vector<int> data2 {1,2,3,4,5};

    Solution s;
    std::cout<<s.isNStraightHand(data1,3)<<std::endl;
    std::cout<<s.isNStraightHand(data2,4)<<std::endl;

    return 0;
}
