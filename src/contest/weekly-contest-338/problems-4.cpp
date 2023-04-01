#include "library.h"

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<unordered_set<int>> next(n);
        for (auto e: edges) {
            next[e[1]].insert(e[0]);
            next[e[0]].insert(e[1]);
        }
        queue<int> q0, q1;
        for (int i = 0; i < n; ++i) {
            if (next[i].size() == 1) {
                (coins[i] == 0 ? q0 : q1).push(i);
            }
        }
        int ans = n-1;
        while (!q0.empty()) {
            --ans;
            int i = q0.front(); q0.pop();
            for (int j : next[i]) {
                next[j].erase(i);
                if (next[j].size() == 1) {
                    (coins[j] == 0 ? q0 : q1).push(j);
                }
            }
        }
        while (!q1.empty()) {
            --ans;
            int i = q1.front(); q1.pop();
            for (int j : next[i]) {
                next[j].erase(i);
                if (next[j].size() == 1) {
                    q0.push(j);
                }
            }
        }
        return max(0, ans-(int)q0.size()) << 1;
    }
};


int main() {
    test(&Solution::collectTheCoins, {
            "[0,0,0,1,1,0,0,1] [[0,1],[0,2],[1,3],[1,4],[2,5],[5,6],[5,7]]",
    });
}