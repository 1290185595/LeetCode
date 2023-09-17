#include "library.h"

class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int ans = 0;
        unordered_map<long long, int> cnt;
        for (auto& c : coordinates) {
            for (int i = 0; i <= k; ++i) {
                ans += cnt[((long long)(c[0] ^ i) << 20) + (c[1] ^ (k-i))];
            }
            ++cnt[((long long)c[0] << 20) + c[1]];
        }
        return ans;
    }
};


int main() {
    test(&Solution::countPairs, {
        "[[1,2],[4,2],[1,3],[5,2]] 5",
        "[[1,3],[1,3],[1,3],[1,3],[1,3]] 0"
    });
}