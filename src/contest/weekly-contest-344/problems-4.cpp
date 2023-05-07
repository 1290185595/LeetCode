#include "library.h"

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for (int i = n >> 1; i > 0; ) {
            int r = i<<1, l = r-1;
            ans += abs(cost[l]-cost[r]);
            cost[--i] += max(cost[l], cost[r]);
        }
        return ans;
    }
};


int main() {
    test(&Solution::minIncrements, {
        "7 [1,5,2,2,3,3,1]"
    });
}