#include "library.h"

class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        long long ans = 0;
        for (int n = nums.size(), i = 1; i <= n; ++i) {
            long long temp = 0;
            for (int j = 1; i * j * j <= n; ++j) {
                temp += nums[i * j * j - 1];
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};


int main() {
    test(&Solution::maximumSum, {
            "[8,7,3,5,7,2,4,9]",
            "[5,10,3,10,1,13,7,9,4]",
    });
}