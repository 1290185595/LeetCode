#include "library.h"

class Solution {
    int maxProduct(int n, long long l, long long r, int budget, vector<int>& composition, vector<int>& stock, vector<int>& cost){
        while (l < r) {
            long long m = (l + r + 1) >> 1, c = 0;
            for (int i = 0; i < n; ++i) {
                c += max(m*composition[i]-stock[i], 0LL) * cost[i];
                if (c > budget) break;
            }
            if (c > budget) r = m - 1;
            else l = m;
        }
        return l;
    }
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int m = budget + *max_element(stock.begin(), stock.end());
        int ans = 0;
        while (k-->0) ans = max(ans, maxProduct(n,0,m,budget,composition[k],stock,cost));
        return ans;
    }
};


int main() {
    test(&Solution::maxNumberOfAlloys, {
        "3 2 15 [[1,1,1],[1,1,10]] [0,0,0] [1,2,3]",
        "3 2 15 [[1,1,1],[1,1,10]] [0,0,100] [1,2,3]",
        "2 3 10 [[2,1],[1,2],[1,1]] [1,1] [5,5]",
    });
}