#include "library.h"

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> va(128);
        iota(va.begin()+'a',va.end(),1);
        for (int i = 0; i < chars.size(); ++i) {
            va[chars[i]] = vals[i];
        }
        int ans = 0, pre = 0;
        for (char c : s) {
            ans = max(ans, pre = max(0, pre + va[c]));
        }
        return ans;
    }
};


int main() {
    test(&Solution::maximumCostSubstring, {
            "adaa d [-1000]",
    });
}