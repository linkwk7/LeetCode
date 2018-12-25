#include <iostream>
#include <vector>
#include <deque>

using std::vector;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<std::pair<int,int>> que;
        std::vector<int> result;

        if (nums.size() == 0 || k == 0) {
            return result;
        }

        for (int i=0; i<k-1; i++) {
            for (; !que.empty() && que.back().first<nums[i]; ) {
                que.pop_back();
            }
            que.push_back(std::make_pair(nums[i], i));
        }

        for (int i=k-1,sz=nums.size(); i<sz; i++) {
            for (; !que.empty() && que.back().first<nums[i]; ) {
                que.pop_back();
            }
            que.push_back(std::make_pair(nums[i], i));
            if ((i-que.front().second) >= k) {
                que.pop_front();
            }
            result.push_back(que.front().first);
        }

        return result;
    }
};

int main() {

}