#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using std::vector;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> que;

        if (nums.size() < k) {
            return -1;
        }

        for (auto iter=nums.begin(); iter!=nums.end(); iter++) {
            que.push(*iter);
            if (que.size() > k) {
                que.pop();
            }
        }

        return que.top();
    }
};

int main() {
    std::vector<int> data {3,2,1,5,6,4};

    Solution s;
    std::cout<<s.findKthLargest(data, 2);

    return 0;
}
