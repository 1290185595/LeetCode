#include "library.h"

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0, n = s.size();
        for (int i = 0; i < n;) {
            int j = i;
            while ((j < n) && (s[j]=='0')) ++j;
            int k = j;
            while ((k < n) && (s[k]=='1')) ++k;
            ans = max(ans, min(k-j, j-i)<<1);
            i = k;
        }
        return ans;
    }
};


int main() {
    test(&Solution::findTheLongestBalancedSubstring, {
    });
}