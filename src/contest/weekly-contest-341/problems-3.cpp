#include "library.h"

class Solution {
public:
    int addMinimum(string word) {
        word += 'a';
        int ans = 0, next = 0;
        for (int c : word) {
            c -= 'a';
            ans += (c + 3 - next) % 3;
            next = (c+1) %3;
        }
        return ans;
    }
};


int main() {
    test(&Solution::addMinimum, {
    });
}