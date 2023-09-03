#include "library.h"

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;

        int idx = 0;
        long long ans = 0;
        for (int num : nums) {
            if (num % modulo == k) idx = (idx + 1) % modulo;
            ans += cnt[(idx-k+modulo) % modulo];
            ++cnt[idx];
        }
        return ans;
    }
};


int main() {
    test(&Solution::countInterestingSubarrays, {
        "[3,1,9,6] 3 0"
    });
}