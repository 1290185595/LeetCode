#include "library.h"

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        vector<int> cnt(2);
        for (char c : s) ++cnt[c-'0'];
        string ans = "";
        while (--cnt[1] > 0) ans.push_back('1');
        while (cnt[0]-- > 0) ans.push_back('0');
        return ans + '1';
    }
};


int main() {
    test(&Solution::maximumOddBinaryNumber, {
    });
}