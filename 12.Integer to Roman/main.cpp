#include <iostream>
#include <vector>
#include <string>

using std::string;

class Solution {
public:
    string intToRoman(int num) {
        std::string result;

        int thousand = num/1000;
        int hundred = (num%1000)/100;
        int ten = (num%100)/10;
        int unit = num%10;

        result += intToRomanUtil(thousand, 6);
        result += intToRomanUtil(hundred, 4);
        result += intToRomanUtil(ten, 2);
        result += intToRomanUtil(unit, 0);

        return result;
    }

    string intToRomanUtil(int n, int pos) {
        static std::vector<char> character {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        std::string result;

        if (n == 0) {
        } else if (n >= 1 && n < 4) {
            for (int i=0; i<n; i++) {
                result += character[pos];
            }
        } else if (n == 4) {
            result += character[pos];
            result += character[pos+1];
        } else if (n > 4 && n < 9) {
            result += character[pos+1];
            for (int i=5; i<n; i++) {
                result += character[pos];
            }
        } else {
            result += character[pos];
            result += character[pos+2];
        }

        return result;
    }
};

int main() {
    Solution s;

    std::cout<<s.intToRoman(3)<<std::endl;

    return 0;
}
