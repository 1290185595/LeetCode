#include "library.h"

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n--); for (int i = 0; i <= n; ++i) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int i, int j){return nums[i] == nums[j] ? (i < j) : nums[i] < nums[j];});
        long long ans = 0;
        for (int i : idx) {
            if (nums[i]) {
                ans += nums[i];
                if (i > 0) nums[i - 1] = 0;
                if (i < n) nums[i + 1] = 0;
            }
        }
        return ans;
    }
};


int main() {
    test(&Solution::findScore, {
            "[2,1,3,4,5,2]",
    });
}