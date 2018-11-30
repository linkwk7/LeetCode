#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> letters {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        std::vector<std::string> result;
        std::string path;

        if (digits.size() != 0) {
            letterCombinationsAux(letters, result, path, digits, 0);
        }
    
        return result;
    }

    void letterCombinationsAux(const std::vector<std::string> & letters, std::vector<std::string> & result, std::string & path, const std::string & digits, int pos) {
        if (pos == digits.size()) {
            result.push_back(path);
            return;
        }

        for (char c : letters[digits[pos]-'0'-2]) {
            path.push_back(c);
            letterCombinationsAux(letters, result, path, digits, pos+1);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;

    auto result = s.letterCombinations("23");

    for (auto s : result) {
        std::cout<<s<<",";
    }

    return 0;
}