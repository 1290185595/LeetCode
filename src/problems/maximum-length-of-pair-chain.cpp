#include "library.h"

/**
 * <a href="https://leetcode.cn/problems/maximum-length-of-pair-chain/">646. 最长数对链</a>
 */

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>&a,vector<int>&b)->bool {return a[1] < b[1];});
        int ans = 0, pre = INT_MIN;
        for(auto& pair: pairs) {
            if (pair.front() > pre) {
                ans++;
                pre = pair.back();
            }
        }
        return ans;
    }
};

int main() {
    test(&Solution::findLongestChain, {
            "[[1,2],[2,3],[3,4]]",
            "[[1,2],[7,8],[4,5]]"
    });
}
