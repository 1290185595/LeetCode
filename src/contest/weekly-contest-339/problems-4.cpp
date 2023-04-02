#include "library.h"

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> ans(n, -1);
        set<int> nums0, nums1;
        for (int i = 0; i <n; ++i) {
            ((i&1) ? nums1 : nums0).insert(i);
        }
        for (int i : banned) ((i&1) ? nums1 : nums0).erase(i);
        queue<int> q;
        q.push(p);
        ((p&1) ? nums1 : nums0).erase(p);
        for (int step = 0; !q.empty(); ++step) {
            for (int num = q.size(); num > 0; --num) {
                p = q.front();
                q.pop();
                ans[p] = step;
                int l = max(0, p-k+1), r = min(p, n-k);
                l = (l << 1) + k - 1 - p;
                r = (r << 1) +k - 1 - p;
                cout << p << l << r << endl;
                auto & nums = (((p&1) ^ !(k&1)) ? nums1 : nums0);
                for (auto ptr = nums.lower_bound(l); (ptr != nums.end()) && (*ptr <= r);){
                    ans[*ptr] = step;
                    q.push(*ptr);
                    ptr = nums.erase(ptr);
                }
            }
        }
        return ans;
    }
};


int main() {
    test(&Solution::minReverseOperations, {
            "5 0 [] 4",
    });
}