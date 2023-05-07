#include "library.h"

class Solution {
public:
    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
        vector<vector<long long>> fields;
        for (auto & f : forceField) {
            long long x = f[0], y = f[1], z = f[2];
            x <<= 1;
            y <<= 1;
            fields.push_back({x - z, x + z, y - z, y + z});
        }
        sort(fields.begin(),fields.end(), [](auto&a, auto&b){
            return a[0] < b[0];
        });
        int ans = 0;
        for (auto i = fields.begin(); i < fields.end(); ++i) {
            map<long long, int> m;
            for (auto j = fields.begin(); j <= i; ++j) {
                if ((*j)[1] >= (*i)[0]) {
                    ++m[(*j)[2]];
                    --m[(*j)[3]+1];
                }
            }
            int cnt = 0;
            for (auto [k,v]:m){
                cnt+=v;
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};


int main() {
    test(&Solution::fieldOfGreatestBlessing, {
            "[[4,4,6],[7,5,3],[1,6,2],[5,6,3]]",
    });
}