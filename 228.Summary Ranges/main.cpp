#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<std::string> result;

        if (nums.size() == 0) {
            return result;
        }

        int begin = nums[0];
        int len = 0;

        for (int i=0,sz=nums.size(); i<sz; i++) {
            if (nums[i] == begin+len) {
                len++;
            } else {
                appendResult(&result, begin, len);

                begin = nums[i];
                len = 1;
            }
        }
        appendResult(&result, begin, len);

        return result;
    }

    void appendResult(std::vector<std::string> * result, int begin, int len) {
        if (len == 1) {
            result->push_back(std::to_string(begin));
        } else {
            result->push_back(std::to_string(begin)+"->"+std::to_string(begin+len-1));
        }
    }
};

int main() {
    Solution s;
    std::vector<int> data {0,1,2,4,5,7};

    std::vector<std::string> result = s.summaryRanges(data);
    std::for_each(result.begin(),result.end(), [](const std::string & arg) {
        std::cout<<arg<<",";
    });

    return 0;
}
