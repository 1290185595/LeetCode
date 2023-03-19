#include "library.h"

class Solution {
public:
    int cal(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n);
        dp[0] = {1, (1 << nums[0]) - 1};
        for (int i = 1; i < n; ++i) {
            dp[i] = {dp[i-1][0] + dp[i-1][1], dp[i-1][0]};
        }
        return dp[n-1][0] + dp[n-1][1];
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> vec;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            if (v == 0) continue;
            vec.push_back({0});
            for (int j = i; j < n; ++j) {
                if (nums[j] == v) {
                    ++(vec.back().back());
                    nums[j]=0;
                } else if (nums[j] == v+k) {
                    v+=k;
                    vec.back().push_back(1);
                    nums[j]=0;
                }
            }
        }
        int ans = 1;
        for (auto & v: vec) ans *= cal(v);
        return ans - 1;
    }
};


int main() {
    test(&Solution::beautifulSubsets, {
            "[4,2,5,9,10,3] 1",
    });
}