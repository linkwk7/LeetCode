#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTAux(nums, 0, nums.size());
    }

    TreeNode* sortedArrayToBSTAux(const std::vector<int>& nums, int begin, int end) {
        if (begin >= end) {
            return NULL;
        }
        int mid = (begin+end)/2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTAux(nums, begin, mid);
        root->right = sortedArrayToBSTAux(nums, mid+1, end);
        return root;
    }
};

int main() {

}