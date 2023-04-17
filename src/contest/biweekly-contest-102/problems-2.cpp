#include "library.h"

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        long long p_max = 0, p_sum = 0;
        vector<long long> ans;
        for (long long v : nums){
            p_max = max(p_max, v);
            p_sum += v + p_max;
            ans.push_back(p_sum);
        }
        return ans;
    }
};


int main() {
    test(&Solution::findPrefixScore, {
            "[2,3,7,5,10]",
    });
}