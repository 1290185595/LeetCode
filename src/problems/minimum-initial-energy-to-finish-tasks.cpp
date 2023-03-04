#include "library.h"

/**
 * <a href="https://leetcode.cn/problems/minimum-initial-energy-to-finish-tasks/">1665. 完成所有任务的最少初始能量</a>
 */

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        auto cmp = [](vector<int>const& a, vector<int>const& b){return a[0]-a[1]<b[0]-b[1];};
        sort(tasks.begin(), tasks.end(), cmp);
        int ans = 0, pre = 0;
        for (auto const& task : tasks) {
            ans = max(ans, pre + task[1]);
            pre += task[0];
        }
        return ans;
    }
};


int main() {
    test(&Solution::minimumEffort, {
        "[[1,2],[2,4],[4,8]]",
        "[[1,3],[2,4],[10,11],[10,12],[8,9]]",
        "[[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]"
    });
}