#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int trap(vector<int>& height) {
        int highest = 0;
        for (int i=1,sz=height.size(); i<sz; i++) {
            highest = (height[i]>height[highest] ? i:highest);
        }

        int total = 0;
        for (int current=0; current<highest; ) {
            int contain = 0;
            int firstHigher = current+1;
            for (; firstHigher<=highest && height[firstHigher]<height[current]; firstHigher++) {
                contain += height[current]-height[firstHigher];
            }
            total += contain;
            current = firstHigher;
        }

        for (int current=height.size()-1; current>=highest; ) {
            int contain = 0;
            int firstHigher = current-1;
            for (; firstHigher>=highest && height[firstHigher]<height[current]; firstHigher--) {
                contain += height[current]-height[firstHigher];
            }
            total += contain;
            current = firstHigher;
        }

        return total;
    }
};

int main() {
    Solution s;

    std::vector<int> data {1,1,1};

    std::cout<<s.trap(data)<<std::endl;

    return 0;
}