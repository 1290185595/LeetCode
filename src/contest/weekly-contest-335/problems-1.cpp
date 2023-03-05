#include "library.h"

class Solution {
public:
    int passThePillow(int n, int time) {
        time %= n << 1;
        return time < n ? time + 1 : (n << 1) - time - 1;
    }
};


int main() {
    test(&Solution::passThePillow, {
            "18 38",
    });
}