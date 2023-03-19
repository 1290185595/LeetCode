#include "library.h"

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        for (int i = 0; n > 0; ++i) {
            if (n&1) ans[i&1]++;
            n >>= 1;
        }
        return ans;
    }
};


int main() {
    test(&Solution::evenOddBit, {
    });
}