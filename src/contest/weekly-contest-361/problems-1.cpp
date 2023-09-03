#include "library.h"

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; ++i) {
            string s = to_string(i);
            if (int n = s.size(); (n & 1) == 0) {
                vector<int> v(s.begin(), s.end());
                n>>=1;
                if (accumulate(v.begin(), v.begin()+n,0)==accumulate(v.begin()+n, v.end(),0)) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};


int main() {
    test(&Solution::countSymmetricIntegers, {
        "1 100",
        "1200 1230"
    });
}