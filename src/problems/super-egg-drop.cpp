#include "library.h"

/**
 * <a href="https://leetcode.cn/problems/super-egg-drop/">887. 鸡蛋掉落</a>
 */


class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> dp = vector<int> (k+1, 0);
        for (int i = 1; true; ++i) {
            for (int j = k; j > 0; --j) {
                if ((dp[j] += dp[j-1]+1) >= n) return i;
            }
        }
    }
};


int main() {
    test(&Solution::superEggDrop, {
            "1 2",
            "2 6",
            "3 14",
    });
}