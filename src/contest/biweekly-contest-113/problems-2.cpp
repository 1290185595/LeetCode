#include "library.h"

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int m = 0, n = nums.size();
        unordered_map<int, int> cnt;
        for (int v : nums) m = max(m, ++cnt[v]);
        n -= m;
        return m > n ? (m - n) : (m+n) & 1;
    }
};


int main() {
    test(&Solution::minLengthAfterRemovals, {
            "[1,3,4,9]",
            "[2,3,6,9]",
            "[1,1,2]",
    });
}