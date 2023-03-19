#include "library.h"

class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        if ((children == 1) && (money == 4)) return -1;
        money -= children;
        int i = money / 7;
        cout << i;
        if ((children-i == 1) && (money % 7 == 3)) --i;
        if ((children == i) && (money % 7 > 0)) --i;
        return i;
    }
};


int main() {
    test(&Solution::distMoney, {
            "20 3",
    });
}