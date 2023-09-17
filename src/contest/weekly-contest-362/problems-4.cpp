#include "library.h"

class Solution {
public:
    int numberOfWays(string s, string t, long long k) {
        t += t;
        int n = s.size(), m = t.size()-1;
        long long mod = 1000000007;
        vector<int> idx;
        vector<vector<int>> jump(n, vector<int>(128));
        jump[0][s[0]] = 1;
        int pre = 0;
        for (int i = 1; i < n; ++i) {
            for (int c = 'a'; c <= 'z'; ++c) {
                jump[i][c] = c == s[i] ? i+1 : jump[pre][c];
            }
            pre = jump[pre][s[i]];
        }
        for (int i = 0, j = 0; i < m; ++i) {
            j = jump[j][t[i]];
            if (j == n) {
                idx.push_back(i-n+1);
                j = pre;
            }
        }
        if (idx.size() == 0) return 0;
        vector<long long> dp = {0, n-1, 1, n-2};
        vector<long long> ans = {1, 0};
        for (long long i = 1; ; ) {
            if (i & k) ans = {
                        (dp[0] * ans[0] + dp[1] * ans[1]) % mod,
                        (dp[2] * ans[0] + dp[3] * ans[1]) % mod
                };
            if ((i <<= 1) > k) break;
            dp = {
                    (dp[0] * dp[0] + dp[1] * dp[2]) % mod,
                    (dp[0] * dp[1] + dp[1] * dp[3]) % mod,
                    (dp[2] * dp[0] + dp[3] * dp[2]) % mod,
                    (dp[2] * dp[1] + dp[3] * dp[3]) % mod
            };
        }
        return (ans[idx[0] == 0 ? 0 : 1] + (idx.size()-1) * ans[1]) % mod;
    }
};


int main() {
    test(&Solution::numberOfWays, {
            "abcd cdab 2",
            "ababab ababab 1",
            "uuuuuuuuu uuuuuuuuu 10"
    });
}