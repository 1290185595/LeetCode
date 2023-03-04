#include "library.h"

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end(), [](auto & a, auto & b){return a[0] < b[0];});
        int n = 0, pre = -1;
        for (auto & r : ranges) {
            cout << pre << ' ' << r[0] << endl;
            if (r[0] > pre) ++n;
            pre = max(pre, r[1]);
        }
        int ans = 1, mod = 1000000007;
        while(n-->0) {
            if ((ans <<= 1) >= mod) ans-= mod;
        }
        return ans;
    }
};


int main() {
    test(&Solution::countWays, {
            "[[34,56],[28,29],[12,16],[11,48],[28,54],[22,55],[28,41],[41,44]]",
    });
}