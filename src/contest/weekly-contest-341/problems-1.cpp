#include "library.h"

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int sum=-1, idx=-1, n = mat.size();
        for (int i = 0; i < n; ++i) {
            int s = accumulate(mat[i].begin(), mat[i].end(),0);
            if (s > sum) {
                sum = s;
                idx = i;
            }
        }
        return {idx, sum};
    }
};


int main() {
    test(&Solution::rowAndMaximumOnes, {
    });
}