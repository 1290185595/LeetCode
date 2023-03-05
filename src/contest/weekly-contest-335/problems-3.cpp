#include "library.h"

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int mod=1000000007;
        vector<int> dp(target+1);
        dp[0] = 1;
        for (auto & t: types) {
            vector<int> tmp(target+1);
            for (int i = target; i >= t[1]; --i) {
                long v = 0;
                for (int j = 0; j <= t[0]; ++j) {
                    int k = i - j * t[1];
                    if (k < 0) break;
                    v += dp[k];
                }
                dp[i] = v % mod;
            }
        }
        return dp[target];
    }
};


int main() {
    test(&Solution::waysToReachTarget, {
            "6 [[6,1],[3,2],[2,3]]",
            "5 [[50,1],[50,2],[50,5]]",
            "18 [[6,1],[3,2],[2,3]]",
    });
}