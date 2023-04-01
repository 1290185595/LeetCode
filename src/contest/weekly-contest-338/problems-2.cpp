#include "library.h"

class Solution {
private:
    set<int> prims;
public:
    bool primeSubOperation(vector<int>& nums) {
        if (nums.back() < nums.size()) return false;
        int m = *max_element(nums.begin(), nums.end());
        vector<bool> isPrims(m, true);
        for (int i = 2; i < m; ++i) {
            if (isPrims[i]) {
                prims.insert(i);
                for (int j = i << 1; j < m; j += i) {
                    isPrims[j] = false;
                }
            }
        }
        for (auto p = nums.rbegin()+1; p < nums.rend(); ++p) {
            if (*p >= *(p-1)) {
                if (prims.upper_bound(*p-*(p-1)) == prims.end()) return false;
                *p -= *prims.upper_bound(*p-*(p-1));
            }
            if (*p < nums.rend() - p) return false;
            cout << *p <<' ';
        }
        return true;
    }
};


int main() {
    test(&Solution::primeSubOperation, {
        "[4,9,6,10]",
        "[6,8,11,12]",
        "[5,8,3]",
        "[2,2]"
    });
}