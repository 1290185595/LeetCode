#include "library.h"

/**
 * <a href="https://leetcode.cn/problems/chalkboard-xor-game/">810. 黑板异或游戏</a>
 */

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int ans = 0;
        for (int v : nums) ans ^= v;
        return ans == 0 || !(nums.size() & 1);
    }
};


int main() {
    test(&Solution::xorGame, {
        "[1,1,2]",
        "[0,1]",
        "[1,2,3]",
    });
}