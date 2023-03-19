#include "library.h"

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0, j = 0, n = nums.size(); true; ++i, ++j) {
            while ((j < n) && (nums[j] <= nums[i])) ++j;
            if (j == n) break;
            ++ans;
        }
        return ans;
    }
};


int main() {
    test(&Solution::maximizeGreatness, {
            "[1,3,5,2,1,3,1]",
    });
}