#include "library.h"

class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size(), end0 = n, end5 = n;
        for (int i = n - 1; i >= 0; --i) {
            if (num[i] == '0') {
                if (end0 < n) {
                    return n - i - 2;
                } else {
                    end0 = i;
                }
            } else if (num[i] == '5') {
                if (end0 < n) {
                    return n - i - 2;
                } else {
                    end5 = i;
                }
            } else if ((end5 < n) && ((num[i] == '2') || (num[i] == '7'))) {
                return n - i - 2;
            }
        }
        if (end0 < n) {
            return n - 1;
        } else {
            return n;
        }
    }
};

int main() {
    test(&Solution::minimumOperations, {
            "2245047",
            "2908305",
            "10"
    });
}