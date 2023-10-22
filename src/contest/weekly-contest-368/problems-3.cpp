#include "library.h"

class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> count_map;
        for (int n: nums) ++count_map[n];
        unordered_map<int, int> value_map;
        int n = INT_MAX;
        for (auto [k, v]: count_map) {
            ++value_map[v];
            n = min(n, v);
        }
        vector<int> dp(n);
        iota(dp.begin(), dp.end(), 1);
        for (auto [k, _]: value_map) {
            vector<int> temp;
            for (int m : dp) {
                if (int a = k / m, b = k % m; b <= a) {
                    temp.push_back(m);
                }
            }
            dp=temp;
        }
        int ans = 0;
        for (auto [k, v]: value_map) ans += (k+dp.back()) / (dp.back()+1) * v;
        return ans;
    }
};

int main() {
    test(&Solution::minGroupsForValidAssignment, {
        "[3,2,3,2,3]",
        "[10,10,10,3,1,1]",
        "[1,1,1,1,1]",
        "[1,1,3,3,1,1,2,2,3,1,3,2]"
    });
}