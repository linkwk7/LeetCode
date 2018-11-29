#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        std::vector<int> result;
        
        for (int i=1; i<10; i++) {
            lexicalOrderAux(result, i, n);
        }

        return result;
    }

    void lexicalOrderAux(std::vector<int> & result, int num, int threshold) {
        if (num > threshold) {
            return;
        }

        result.push_back(num);
        num *= 10;

        for (int i=0; i<10; i++) {
            if (num + i <= threshold) {
                lexicalOrderAux(result, num+i, threshold);
            } else {
                return;
            }
        }
    }
};

int main() {

}