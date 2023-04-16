#include "library.h"

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, long long> cnt, sum;
        int n = nums.size();
        vector<long long> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = cnt[nums[i]] * i - sum[nums[i]];
            cnt[nums[i]]++;
            sum[nums[i]]+=i;
        }
        for (int i = 0; i < n; ++i) {
            ans[i] = sum[nums[i]] + (ans[i] << 1) - cnt[nums[i]] * i;
        }
        return ans;
    }
};

int main() {
    test(&Solution::distance, {
        "[1,3,1,1,2]",
    });
}