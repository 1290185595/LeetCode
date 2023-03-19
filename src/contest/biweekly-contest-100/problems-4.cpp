#include "library.h"

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        unordered_map<int, int> r_c;
        for (int r: ranks) r_c[r]++;
        unordered_map<int, long long> c_c;
        priority_queue<int, vector<int>, function<bool(int, int)>> q([&](int i, int j) {
            long long _i = (long long)i* (c_c[i]+1)* (c_c[i]+1), _j = (long long)j* (c_c[j]+1)* (c_c[j]+1);
            return _i == _j ? i > j : _i > _j;
        });
        for (auto [k, v]: r_c) {
            c_c[k] = 0;
            q.push(k);
        }
        while (cars > 0) {
            int k = q.top();
            q.pop();
            cars -= r_c[k];
            ++c_c[k];
            q.push(k);
        }
        long long ans = 0;
        for (auto [k, v] : c_c) ans = max(ans, (long long) k * v * v);
        return ans;
    }
};

int main() {
    test(&Solution::repairCars, {
            "[4,2,3,1] 10",
    });
}