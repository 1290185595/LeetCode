#include "library.h"

class Solution {
public:
    int splitNum(int num) {
        vector<int> vec;
        while (num > 0) {
            vec.push_back(num%10);
            num/=10;
        }
        sort(vec.begin(), vec.end());
        vector<int> ans(2);
        int i = 0;
        for (int v: vec) {
            ans[i] = ans[i] * 10 + v;
            i ^= 1;
        }
        return ans[0]+ans[1];
    }
};


int main() {
    test(&Solution::temperatureTrend, {
            "[21,18,18,18,31] [34,32,16,16,17]",
    });
}