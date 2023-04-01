#include "library.h"

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<int> idx(queries.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j){return queries[i] < queries[j];});
        sort(nums.begin(), nums.end());
        long  long n = nums.size(), j = 0;
        long long sum = 0, pre = 0;
        for (int v : nums) sum += v;
        vector<long long> ans(queries.size());
        for (int i : idx) {
            while ((j < n) && (nums[j] < queries[i])) {
                pre += nums[j++];
            }
            ans[i] = sum + (j * queries[i] - pre) * 2 - n * queries[i];
        }
        return ans;
    }
};


int main() {
    test(&Solution::minOperations, {
            "[3,1,6,8] [1,5]",
    });
}