#include "library.h"

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        sort(divisors.begin(), divisors.end());
        int sum = -1, idx = -1;
        for (int i : divisors) {
            int s = 0;
            for (int v : nums) {
                if (v % i == 0) {
                    ++s;
                }
            }
            if (s > sum) {
                sum = s;
                idx = i;
            }
        }
        return idx;
    }
};

int main() {
    test(&Solution::maxDivScore, {
    });
}