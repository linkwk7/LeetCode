#include <iostream>
#include <vector>
#include <stack>

using std::vector;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::vector<std::pair<int,int>> stk;
        std::vector<int> rightBound(heights.size(), heights.size());
        for (int i=0,sz=heights.size(); i<sz; i++) {
            if (stk.empty()) {
                stk.push_back(std::make_pair(heights[i], i));
            } else {
                for (; !stk.empty() && stk.back().first>heights[i]; ) {
                    rightBound[stk.back().second] = i;
                    stk.pop_back();
                }
                stk.push_back(std::make_pair(heights[i], i));
            }
        }
        
        stk.clear();
        std::vector<int> leftBound(heights.size(), -1);
        for (int i=heights.size()-1; i>=0; i--) {
            if (stk.empty()) {
                stk.push_back(std::make_pair(heights[i], i));
            } else {
                for (; !stk.empty() && stk.back().first>heights[i]; ) {
                    leftBound[stk.back().second] = i;
                    stk.pop_back();
                }
                stk.push_back(std::make_pair(heights[i], i));
            }
        }

        int max = 0;
        for (int i=0,sz=heights.size(); i<sz; i++) {
            max = std::max(max, (rightBound[i]-leftBound[i]-1)*heights[i]);
        }
        return max;
    }
};

int main() {
    std::vector<int> data {2,1,5,6,2,3};

    Solution s;

    std::cout<<s.largestRectangleArea(data);

    return 0;
}