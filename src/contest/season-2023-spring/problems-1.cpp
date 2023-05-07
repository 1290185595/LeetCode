#include "library.h"

class Solution {
public:
    vector<int> supplyWagon(vector<int> &supplies) {
        int n = supplies.size() >> 1;
        while (supplies.size() > n) {
            auto p = supplies.begin() + 1;
            int sum = *(p - 1) + *p;
            for (auto q = p + 1; q < supplies.end(); ++q) {
                if (int v = *(q - 1) + *q; v < sum) {
                    p = q;
                    sum = v;
                }
            }
            *(p-1)+=*p;
            supplies.erase(p);
        }
        return supplies;
    }
};


int main() {
    test(&Solution::supplyWagon, {
            "[7,3,6,1,8]",
    });
}