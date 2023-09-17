#include "library.h"

class Solution {
    int bit_count(int v) {
        int ans = 0;
        while (v > 0) {
            ans += v & 1;
            v >>= 1;
        }
        return ans;
    }
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (bit_count(i) == k) ans += nums[i];
        }
        return ans;
    }
};


int main() {
    test(&Solution::sumIndicesWithKSetBits, {
    });
}