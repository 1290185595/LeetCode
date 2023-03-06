#include "library.h"

/**
 * <a href="https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel/">1599. 经营摩天轮的最大利润</a>
 */

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        if ((boardingCost << 2) <= runningCost) return -1;
        int ans = -1, income = 0, max_income = 0, waiting = 0, n = customers.size();
        for (int i = 0; i < n; ) {
            waiting += customers[i++];
            int c = min(waiting, 4);
            waiting -= c;
            income += c * boardingCost- runningCost;
            if (income > max_income) {
                max_income = income;
                ans = i;
            }
        }

        int r = waiting >> 2, w = waiting & 3;
        income += r * ((boardingCost << 2) - runningCost);
        if (boardingCost * w > runningCost) {
            ++r;
            income += boardingCost * w - runningCost;
        }
        return income > max_income ? n + r : ans;
    }
};

int main() {
    test(&Solution::minOperationsMaxProfit, {
            "[8,3] 5 6",
            "[10,9,6] 6 4",
            "[3,4,0,5,1] 1 92",
    });
}
