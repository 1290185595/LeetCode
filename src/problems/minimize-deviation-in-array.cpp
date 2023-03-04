#include "library.h"

/**
 * <a href="https://leetcode.cn/problems/minimize-deviation-in-array/">1675. 数组的最小偏移量</a>
 */

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int minValue = INT_MAX;
        priority_queue<int> q;
        for (int num: nums) {
            if (num & 1) num <<= 1;
            minValue = min(minValue, num);
            q.push(num);
        }
        int ans = q.top() - minValue;
        for (int num = q.top(); (num & 1) == 0; num = q.top()) {
            if (ans == 0) break;
            q.pop();
            num >>= 1;
            minValue = min(minValue, num);
            q.push(num);
            ans = min(ans, q.top() - minValue);
        }
        return ans;
    }
};
int main() {
    test(&Solution::minimumDeviation, {
//            "[1,2,3,4]",
//            "[4,1,5,20,3]",
//            "[2,10,8]",
            "[9,4,3,6,2]"
    });
}
