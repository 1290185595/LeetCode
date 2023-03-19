#include "library.h"

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;
        int n = grid.size();
        vector<vector<int>> p(n*n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                p[grid[i][j]][0] = i;
                p[grid[i][j]][1] = j;
            }
        }
        for (int i = 1, m = n * n; i < m; ++i) {
            int v = 0;
            for (int j = 0; j < 2; ++j) {
                int d = abs(p[i][j]-p[i-1][j]);
                if (d == 1) v |= 1;
                else if (d == 2) v |= 2;
                else return false;
            }
            if (v != 3) return false;
        }
        return true;
    }
};


int main() {
    test(&Solution::checkValidGrid, {
        "[[24,11,22,17,4],[21,16,5,12,9],[6,23,10,3,18],[15,20,1,8,13],[0,7,14,19,2]]"
    });
}