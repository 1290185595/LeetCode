#include "library.h"

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> next(n);
        for (auto & e : edges) {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        vector<int> cnt(n);

        function<bool(int,int,int)> dfs= [&](int p, int i, int e) {
            if (i == e) {
                ++cnt[i];
                return true;
            }
            for (int j : next[i]) {
                if ((j != p) && dfs(i, j, e)) {
                    ++cnt[i];
                    return true;
                }
            }
            return false;
        };
        for (auto & t : trips) dfs(-1,t[0],t[1]);

        vector<vector<int>> dp(n, vector<int>(2, INT_MAX));
        function<int(int,int,int)> minCost= [&](int pre, int i, int status) {
            if (dp[i][status] == INT_MAX) {
                dp[i][status] = (price[i] >> status) * cnt[i];
                for (int j : next[i]) {
                    if (j == pre) continue;
                    if (status == 1) dp[i][status] += minCost(i,j,0);
                    else dp[i][status] += min(minCost(i,j,0), minCost(i,j,1));
                }
            }
            return dp[i][status];
        };
        return min(minCost(-1,0,0),minCost(-1,0,1));

    }
};


int main() {
    test(&Solution::minimumTotalPrice, {
        "4 [[0,1],[1,2],[1,3]] [2,2,10,6] [[0,3],[2,1],[2,3]]"
    });
}