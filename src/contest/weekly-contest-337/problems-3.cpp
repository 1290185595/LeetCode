#include "library.h"

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> m = {{0, 1}};
        int pre = 0;
        long long ans = 0;
        for (int n : nums) {
            pre ^= n;
            ans += m[pre]++;
        }
        return ans;
    }
};


int main() {
    test(&Solution::beautifulSubarrays, {
            "[4,3,1,2,4]",
            "[1,10,4]",
    });
}