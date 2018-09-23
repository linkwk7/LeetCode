#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size()-1;

        for (; left<right; ) {
            int area = (right-left)*std::min(height[left], height[right]);

            if (area > maxArea) {
                maxArea = area;
            }

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};

int main() {


    return 0;
}