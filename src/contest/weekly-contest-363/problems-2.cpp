#include "library.h"

class Solution {
public:
    int countWays(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = (0 < nums[0]) + (n > nums[n - 1]);
        for (int i = 1; i < n; ++i) {
            ans += (i > nums[i - 1]) && (i < nums[i]);
        }
        return ans;
    }
};

int main() {
    test(&Solution::countWays, {
            "[1,1]",
            "[6,0,3,3,6,7,2,7]"
    });
}