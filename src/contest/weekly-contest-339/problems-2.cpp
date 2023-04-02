#include "library.h"

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> c(n+1);
        for (int i : nums) ++c[i];
        vector<vector<int>> ans(*max_element(c.begin(), c.end()));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < c[i]; ++j) {
                ans[j].push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    test(&Solution::findMatrix, {
        "[1,3,4,1,2,3,1]",
    });
}