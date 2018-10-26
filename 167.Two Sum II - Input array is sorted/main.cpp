#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first = 0;
        int last = numbers.size()-1;

        for (; first<last; ) {
            int sum = numbers[first]+numbers[last];
            if (sum == target) {
                return std::vector<int>{first+1,last+1};
            } else if (sum > target) {
                last--;
            } else {
                first++;
            }
        }
    }
};

int main() {
    Solution s;

    std::vector<int> data {2,7,11,15};
    std::vector<int> result = s.twoSum(data, 9);

    for (int elem : result) {
        std::cout<<elem<<",";
    }

    return 0;
}