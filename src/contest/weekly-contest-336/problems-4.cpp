#include "library.h"
#include <iterator>

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size(), m = 2000;
        vector<unordered_set<int>> rely(m);
        vector<int>rely_index(m);
        for (int i = 0; i < m; ++i) rely_index[i] = i;
        for (int i = 0; i < n; ++i) {
            int start = tasks[i][0]-1, end = tasks[i][1];
            for (int j = start; j < end; ++j) {
                rely[j].insert(i);
            }
        }
        sort(rely_index.begin(), rely_index.end(), [&](auto &a, auto &b){return rely[a].size()>rely[b].size();});
        int ans = 0, r = 0;
        for (auto s : rely) if(!s.empty()) r++;
        while (true) {
            sort(rely_index.begin(), rely_index.begin()+r, [&](auto &a, auto &b){return rely[a].size()>rely[b].size();});
            int k = rely_index[0];
            if (rely[k].empty()) break;
            ++ans;
            for (int i : rely[k]) {
                if (--tasks[i][2] == 0) {
                    int start = tasks[i][0] - 1, end = tasks[i][1];
                    for (int j = start; j < end; ++j) {
                        if (j != k) {
                            rely[j].erase(i);
                            if (rely[j].empty()) --r;
                        }
                    }
                }
            }
            rely[k].clear();
        }
        return ans;
    }
};


int main() {
    test(&Solution::findMinimumTime, {
            "[[2,3,1],[4,5,1],[1,5,2]]",
            "[[1,2000,2000]]",
    });
}