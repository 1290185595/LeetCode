#include "library.h"

class Solution {
public:
    int adventureCamp(vector<string> &expeditions) {
        int n = expeditions.size();
        unordered_set<string> viewed;
        string delimiter = "->";
        auto parse = [&](string &s) {
            if (s == "") return 0;
            s += delimiter;
            int cnt = 0;
            for (int i = 0, j; (j = s.find(delimiter, i)) != s.npos; i = j + 2) {
                string ne = s.substr(i, j - i);
                if (viewed.find(ne) == viewed.end()) {
                    viewed.insert(ne);
                    ++cnt;
                }
            }
            return cnt;
        };
        parse(expeditions[0]);
        int ans = -1, num = 0;
        for (int i = 1; i < n; ++i) {
            if (int v = parse(expeditions[i]); v > num) {
                ans = i;
                num = v;
            }
        }
        return ans;
    }
};


int main() {
    test(&Solution::adventureCamp, {
            "[leet->code,leet->code->Campsite->Leet,leet->code->leet->courier]",
    });
}