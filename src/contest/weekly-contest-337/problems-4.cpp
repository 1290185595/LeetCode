#include "library.h"

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> c(value);
        for (int n : nums) {
            c[((n % value) + value) % value] ++;
        }
        int idx = 0, v = c[0];
        for (int i = 1; i < value; ++i) {
            if (c[i] < v) {
                idx = i;
                v = c[i];
            }
        }
        return idx + v * value;
    }
};


int main() {
    test(&Solution::findSmallestInteger, {
            "[1,-10,7,13,6,8] 5",
    });
}