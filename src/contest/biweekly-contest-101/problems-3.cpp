#include "library.h"

class Solution {
public:
    long long count(vector<int>& arr){
        sort(arr.begin(), arr.end());
        int a = arr[arr.size()>>1];
        long long ans = 0;
        for (int v: arr) ans += ::abs(v - a);
        return ans;
    }
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        k = gcd(n, k);
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> tmp;
            for (int j = i; j < n; j += k) tmp.push_back(arr[j]);
            ans += count(tmp);
        }
        return ans;
    }
};


int main() {
    test(&Solution::makeSubKSumEqual, {
            "[2,10,9] 1",
    });
}