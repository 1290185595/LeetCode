#include "library.h"

class Solution {
    vector<vector<vector<int>>> matrix;
    vector<vector<int>> next;
    int dfs(int i, int start, int pre, int cur, int end, int sum) {
        if (cur == end)
    };
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>> &edges, vector<vector<int>> &queries) {
        int m = 26;
        matrix = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(n, -1)));
        next = vector<vector<int>>(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j][j] = 0;
            }
        }
        for (auto &e: edges) {
            --e[2];
            for (int i = 0; i < m; ++i) {
                int v = e[2] != i;
                matrix[i][e[0]][e[1]] = v;
                matrix[i][e[1]][e[0]] = v;
            }
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        vector<int> ans;
        for (auto &q: queries) {
            int temp = INT_MAX;
            for (int i = 0; i < m; ++i) {
                temp = min(temp, dfs(i,q[0],q[0],q[0],q[1]));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


int main() {
    test(&Solution::minOperationsQueries, {
            "7 [[0,1,1],[1,2,1],[2,3,1],[3,4,2],[4,5,2],[5,6,2]] [[0,3],[3,6],[2,6],[0,6]]"
    });
}