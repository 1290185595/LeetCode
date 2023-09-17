#include "library.h"

class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int reverse = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i-1]) {
                if (reverse > 0) return -1;
                reverse = n - i;
            }
        }
        return reverse == 0 ? 0 : nums[n-1] < nums[0] ? reverse : -1;
    }
};


int main() {
    test(&Solution::minimumRightShifts, {
            "[3,4,5,1,2]",
            "[1,3,5]",
            "[2,1,4]",
    });
}