#include "library.h"

class Solution {
public:
    int findShortest(int n, vector<unordered_set<int>>& next, int begin, int end) {
        vector<bool> viewed(n);
        queue<int> q;
        q.push(begin);
        viewed[begin] = true;
        for (int step = 1; !q.empty(); ++step) {
            for (int num = q.size(); num > 0; --num) {
                for (int j: next[q.front()]) {
                    if (j == end) return step;
                    if (!viewed[j]) {
                        q.push(j);
                        viewed[j] = true;
                    }
                }
                q.pop();
            }
        }
        return n;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> next(n);
        for (auto & e : edges) {
            next[e[0]].insert(e[1]);
            next[e[1]].insert(e[0]);
        }
        int ans = n;
        for (auto & e : edges) {
            next[e[0]].erase(e[1]);
            next[e[1]].erase(e[0]);
            ans = min(ans, findShortest(n, next, e[0], e[1]));
            next[e[0]].insert(e[1]);
            next[e[1]].insert(e[0]);
        }
        return ans == n ? -1 : ans+1;
    }
};


int main() {
    test(&Solution::findShortestCycle, {
            "4 [[0,1],[0,2]]",
    });
}