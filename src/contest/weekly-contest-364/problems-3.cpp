#include "library.h"

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> front(n),back(n);
        --n;
        stack<pair<long long, int>> pre;
        long long sum = 0;
        for (int i = 0; i <= n; ++i) {
            int cnt = 1;
            while ((!pre.empty()) && (pre.top().first >= maxHeights[i])) {
                sum -= (pre.top().first - maxHeights[i]) * pre.top().second;
                cnt += pre.top().second;
                pre.pop();
            }
            front[i] = sum;
            sum += maxHeights[i];
            pre.push({maxHeights[i],cnt});
        }
        stack<pair<long long, int>> pre2;
        long long sum2 = 0;
        for (int i = n; i >= 0; --i) {
            int cnt = 1;
            while ((!pre2.empty()) && (pre2.top().first >= maxHeights[i])) {
                sum2 -= (pre2.top().first - maxHeights[i]) * pre2.top().second;
                cnt += pre2.top().second;
                pre2.pop();
            }
            back[i] = sum2;
            sum2 += maxHeights[i];
            pre2.push({maxHeights[i],cnt});
        }
        long long ans = 0;
        for (int i = 0; i <= n; ++i) {
            ans = max(maxHeights[i] + front[i] + back[i], ans);
        }
        return ans;
    }
};

int main() {
    test(&Solution::maximumSumOfHeights, {
            "[5,3,4,1,1]",
            "[6,5,3,9,2,7]",
            "[3,2,5,5,2,3]"
    });
}