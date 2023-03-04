#include "library.h"

/**
 * <a href="https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/">857. 雇佣 K 名工人的最低成本</a>
 */

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<int> index;
        vector<double> wagePerQuality;
        for(int i = 0; i < n; ++i) {
            index.push_back(i);
            wagePerQuality.push_back(double (wage[i]) / quality[i]);
        }
        sort(index.begin(), index.end(), [&](int &a, int &b){
            return wagePerQuality[a] < wagePerQuality[b];
        });
        int sumQuality = 0;
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < k; ++i) {
            int idx = index[i];
            sumQuality += quality[idx];
            q.push(quality[idx]);
        }
        double ans = sumQuality * wagePerQuality[index[--k]];
        while (++k<n){
            int idx = index[k];
            sumQuality -= q.top();
            q.pop();
            sumQuality += quality[idx];
            q.push(quality[idx]);
            ans = min(ans, sumQuality * wagePerQuality[idx]);
        }
        return ans;
    }
};


int main() {
    test(&Solution::mincostToHireWorkers, {
            "[10,20,5] [70,50,30] 2",
            "[3,1,10,10,1] [4,8,2,2,7] 3"
    });
}
