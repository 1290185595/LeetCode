#include "library.h"

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        ++n;
        vector<unordered_map<int, long long>> next(n);
        for (auto& e: edges) {
            next[e[0]][e[1]] = 0;
            next[e[1]][e[0]] = 0;
        }
        vector<bool> isPrime(n, true);
        isPrime[1] = false;
        for (int i = 2; i < n; ++i) if (isPrime[i]) for (int j = i << 1; j < n; j += i) isPrime[j] = false;
        function<long long (int, int)> view = [&](int pre, int cur) {
            if (isPrime[cur]) return 0LL;
            if (next[pre][cur] == 0) {
                next[pre][cur] = 1;
                for (auto [nxt,_] : next[cur]) {
                    if (nxt != pre) {
                        next[pre][cur] += view(cur, nxt);
                    }
                }
            }
            return next[pre][cur];
        };
        long long ans = 0;
        for (int cur = 1; cur < n; ++cur) {
            if (isPrime[cur]) {
                long long sum = 1;
                for (auto [nxt,_] : next[cur]) {
                    ans += sum * view(cur, nxt);
                    sum += view(cur, nxt);
                }
            }
        }
        return ans;
    }
};


int main() {
    test(&Solution::countPaths, {
            "5 [[1,2],[1,3],[2,4],[2,5]]",
            "6 [[1,2],[1,3],[2,4],[3,5],[3,6]]",
    });
}