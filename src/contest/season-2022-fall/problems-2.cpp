#include "library.h"

class Solution {
public:
    int transportationHub(vector<vector<int>>& path) {
        unordered_map<int, unordered_set<int>> from;
        unordered_set<int> to;
        for (auto const& p: path) {
            if (from.count(p[1]) == 0) from[p[1]] = {p[0]};
            else from[p[1]].emplace(p[0]);
            if (from.count(p[0]) == 0) from[p[0]];
            to.emplace(p[0]);
        }
        for (auto entry: from) {
            if (to.count(entry.first) == 0 && entry.second.size() == from.size()-1) return entry.first;
        }
        return -1;
    }
};


int main() {
    test(&Solution::transportationHub, {
            "[[0,1],[0,3],[1,3],[2,0],[2,3]]",
    });
}