#include "library.h"

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        unordered_map<int, int> color;
        vector<int> ans;
        int cnt = 0;
        for (auto& q : queries) {
            if (color[q[0]]!=q[1]) {
                if (color[q[0]]!=0){
                    if (color[q[0]-1] == color[q[0]]) --cnt;
                    if (color[q[0]+1] == color[q[0]]) --cnt;
                }
                color[q[0]]=q[1];
                if (color[q[0]-1] == color[q[0]]) ++cnt;
                if (color[q[0]+1] == color[q[0]]) ++cnt;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


int main() {
    test(&Solution::colorTheArray, {
    });
}