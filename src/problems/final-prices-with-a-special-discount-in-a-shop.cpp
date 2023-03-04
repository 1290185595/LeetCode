#include "library.h"

/**
 * <a href="https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/">1475. 商品折扣后的最终价格</a>
 */

class Solution {
public:
    vector<int> finalPrices(vector<int> &prices) {
        vector<int> q;
        for (int j = 0; j < prices.size(); ++j) {
            while (!q.empty() && prices[j] <= prices[q.back()]) {
                prices[q.back()] -= prices[j];
                q.pop_back();
            }
            q.push_back(j);
        }
        return prices;
    }
};



int main() {
    test(&Solution::finalPrices, {
        "[8,4,6,2,3]",
        "[1,2,3,4,5]",
        "[10,1,1,6]"
    });
}
