#include "library.h"

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        long sum = 0;
        int ans = 0;
        for (int v : nums) {
            if ((sum+=v)<=0) break;
            ++ans;
        }
        return ans;
    }
};


int main() {
    test(&Solution::maxScore, {
    });
}