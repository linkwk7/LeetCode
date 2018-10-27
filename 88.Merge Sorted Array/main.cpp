#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m+n-1;
        int index1 = m-1;
        int index2 = n-1;

        for (; index1>=0 || index2>=0; ) {
            if (index2 < 0) {
                break;
            }

            if (index1 >= 0 && (nums1[index1] > nums2[index2])) {
                nums1[index--] = nums1[index1--];
            } else {
                nums1[index--] = nums2[index2--];
            }
        }
    }
};

int main() {
    Solution s;

    std::vector<int> data0 {1,2,3,0,0,0};
    std::vector<int> data1 {2,5,6};

    s.merge(data0, 3, data1, 3);

    for (int elem : data0) {
        std::cout<<elem<<",";
    }

    return 0;
}
