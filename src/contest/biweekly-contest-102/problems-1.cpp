#include "library.h"

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for (auto& g : grid) {
            transform(g.begin(), g.end(), ans.begin(), ans.begin(), [](int v, int a){
                return max((int)to_string(v).size(), a);
            });
        }
        return ans;
    }
};


int main() {
    test(&Solution::findColumnWidth, {
            "[[1],[22],[333]]",
    });
}