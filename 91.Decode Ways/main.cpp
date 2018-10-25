#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() < 2) {
            return s.size()==0 ? 0:(s[0]=='0' ? 0:1);
        }

        int im2 = 1;
        int im1 = (s[0] == '0' ? 0:1);
        for (int i=1,sz=s.size(); i<sz; i++) {
            int cur = 0;
            if (s[i] >= '1' && s[i] <= '9') {
                cur += im1;
            }
            int num = (s[i-1]-'0')*10 + (s[i]-'0');
            if (num <= 26 && num >= 10) {
                cur += im2;
            }
            im2 = im1;
            im1 = cur;
        }
        return im1;
    }
};

int main() {
    Solution s;

    std::cout<<s.numDecodings("01")<<std::endl;

    return 0;
}
