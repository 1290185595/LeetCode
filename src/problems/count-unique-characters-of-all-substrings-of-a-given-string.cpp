#include "library.h"

/**
 * <a href="https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/">828. 统计子串中的唯一字符</a>
 */

class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<vector<int>> last = vector<vector<int>>(26, {-1,0});
        int ans = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'A';
            sum -= last[c][1];
            last[c][1] = i - last[c][0];
            last[c][0] = i;
            sum += last[c][1];
            ans += sum;
        }
        return ans;
    }
};



int main() {
    test(&Solution::uniqueLetterString, {
            "ABC",
            "ABA",
            "LEETCODE"
    });
}
