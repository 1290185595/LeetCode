#include "library.h"

class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<unordered_map<int, int>> next(n);
        for (auto& e : edges) {
            next[e[0]][e[1]] = 0;
            next[e[1]][e[0]] = 1;
        }
        vector<unordered_map<int, int>> dp(n+1);
        function<int(int, int)> dfs = [&](int pre, int cur){
            auto& m = dp[pre];
            if (m.find(cur) == m.end()) {
                for (auto [k, v] : next[cur]) {
                    if (k != pre) m[cur] += dfs(cur, k) + v;
                }
            }
            return m[cur];
        };
        vector<int> ans;
        for (int i = 0; i < n; ++i) ans.push_back(dfs(n, i));
        return ans;
    }
};


int main() {
    test(&Solution::minEdgeReversals, {
            "4 [[2,0],[2,1],[1,3]]",
            "3 [[1,2],[2,0]]"
    });
}