#include "library.h"

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> prefix = nums, suffix = nums;
        function<int(int, int)> mini = [&](int a, int b) {return min(a, b);};
        transform(nums.begin(), nums.end()-1, prefix.begin(), prefix.begin()+1, mini);
        transform(nums.rbegin(), nums.rend()-1, suffix.rbegin(), suffix.rbegin()+1, mini);
        int ans = INT_MAX, n = nums.size()-1;
        for (int i = 1; i < n; ++i) {
            if (nums[i]>max(prefix[i], suffix[i])) {
                ans = min(ans, nums[i]+prefix[i]+suffix[i]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};


int main() {
    test(&Solution::minimumSum, {
        "[8,6,1,5,3]"
    });
}