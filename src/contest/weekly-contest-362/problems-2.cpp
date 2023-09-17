#include "library.h"

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int d = max(abs(sx-fx), abs(sy-fy));
        return d == 0 ? t != 1 : t >= d;
    }
};

int main() {
    test(&Solution::isReachableAtTime, {
            "2 4 7 7 6",
            "3 1 7 3 3"
    });
}