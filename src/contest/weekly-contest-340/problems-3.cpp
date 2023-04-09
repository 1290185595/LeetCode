#include "library.h"

class Solution {
public:
    bool ok(vector<int>& nums, int p, int v) {
        for (int i = 1, n = nums.size(); i < n; ++i) {
            if (nums[i] - nums[i-1] <= v) {
                if (--p == 0) return true;
                ++i;
            }
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = INT_MAX;
        while (l < r) {
            int m = l + ((r - l) >> 2);
            if (ok(nums, p, m)) r = m;
            else l = m+1;
        }
        return r;
    }
};


int main() {
    test(&Solution::minimizeMax, {
            "[8,9,1,5,4,3,6,4,3,7] 4",
    });
}