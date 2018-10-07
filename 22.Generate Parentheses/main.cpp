#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        
        generateParenthesisAux(result, "", 0, 0, n);

        return result;
    }

    void generateParenthesisAux(std::vector<std::string> & result, std::string path, int open, int close, int max) {
        if (path.length() == 2*max) {
            result.push_back(path);
        }

        if (open < max) {
            generateParenthesisAux(result, path+"(", open+1, close, max);
        }
        if (close < open) {
            generateParenthesisAux(result, path+")", open, close+1, max);
        }
    }
};

int main() {
    Solution s;

    std::vector<std::string> result = s.generateParenthesis(3);
    for (auto s : result) {
        std::cout<<s<<std::endl;
    }

    return 0;
}
