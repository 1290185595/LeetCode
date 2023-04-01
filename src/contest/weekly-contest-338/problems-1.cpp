#include "library.h"

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        return min(k, numOnes) - max(k-numOnes-numZeros, 0);

    }
};


int main() {
    test(&Solution::kItemsWithMaximumSum, {
    });
}