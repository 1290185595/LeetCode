#include "library.h"

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end()), n = nums.size();
        vector<int> cnt(m + 1, 0);
        vector<int> pre(n);
        for (int i = 0, j = 0; i < n; ++i) {
            if (cnt[nums[i]]++ == 0) ++j;
            pre[i] = j;
        }
        fill(cnt.begin(), cnt.end(), 0);
        vector<int> ans(n);
        for (int i = n-1, j = 0; i >= 0; --i) {
            ans[i] = pre[i] - j;
            if (cnt[nums[i]]++ == 0) ++j;
        }
        return ans;
    }
};


int main() {
    test(&Solution::distinctDifferenceArray, {
        "[1,2,3,4,5]"
    });
}