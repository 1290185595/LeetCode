#include "library.h"

class Solution {
public:
    bool isPrim(int v) {
        if (v == 1) return false;
        for (int i = 2; i * i <= v; ++i) {
            if (v % i == 0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans = 0;
        for (int i = 0, n = nums.size() - 1; i <= n; ++i) {
            if (isPrim(nums[i][i])) ans = max(ans, nums[i][i]);
            if (isPrim(nums[i][n-i])) ans = max(ans, nums[i][n-i]);
        }
        return ans;
    }
};


int main() {
    test(&Solution::diagonalPrime, {
    });
}