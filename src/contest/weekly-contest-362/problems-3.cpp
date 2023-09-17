#include "library.h"

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<int>> blank, full;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j]==0) blank.push_back({i,j});
                else while (--grid[i][j] > 0) full.push_back({i,j});
            }
        }
        int m = blank.size(), n = full.size();
        vector<vector<int>> dist(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = abs(blank[i][0]-full[j][0]) + abs(blank[i][1]-full[j][1]);
            }
        }
        vector<int> dp(1 << m, -1);
        function<int(int, int)> dfs = [&](int used, int idx) {
            if (idx >= n) return 0;
            if (dp[used] == -1) {
                dp[used] = INT_MAX;
                for (int i = 0; i < n; ++i) {
                    if ((used & (1 << i)) == 0) {
                        dp[used] = min(dp[used], dfs(used | (1 << i), idx+1) + dist[idx][i]);
                    }
                }
            }
            return dp[used];
        };
        return dfs(0, 0);
    }
};


int main() {
    test(&Solution::minimumMoves, {
        "[[1,1,0],[1,1,1],[1,2,1]]",
        "[[1,3,0],[1,0,0],[1,0,3]]"
    });
}