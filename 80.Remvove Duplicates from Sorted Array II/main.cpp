#include <vector>
#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for (int i=0,sz=nums.size(); i<sz; i++) {
            std::cout<<nums[i]<<" "<<nums[i-2]<<" "<<index<<std::endl;
            if (i < 2 || nums[i] != nums[index-2]) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

int main() {
    std::vector<int> data {1,1,1,2,2,3};

    Solution s;
    int i = s.removeDuplicates(data);

    std::for_each(data.begin(),data.begin()+i, [](int arg) {
        std::cout<<arg<<",";
    });

    return 0;
}
