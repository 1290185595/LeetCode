#include "library.h"

class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int ans = 0, pre = 0;
        return ans;
    }
};


int main() {
    test(&Solution::temperatureTrend, {
            "[21,18,18,18,31] [34,32,16,16,17]",
    });
}