#include "library.h"

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int> s;
        for (auto& n : nums) {
            for (int i = n[0]; i <= n[1]; ++i) {
                s.insert(i);
            }
        }
        return s.size();
    }
};


int main() {
    test(&Solution::numberOfPoints, {
        "[[3,6],[1,5],[4,7]]",
        "[[1,3],[5,8]]"
    });
}