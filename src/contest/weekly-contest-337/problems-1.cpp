#include "library.h"

class Solution {
private:
    bool isAEIOU(char & c) {
        if (c == 'a') return true;
        if (c == 'e') return true;
        if (c == 'i') return true;
        if (c == 'o') return true;
        if (c == 'u') return true;
        return false;
    }
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        for (int i = left; i < right; ++i) {
            if (isAEIOU(words[i].front()) && isAEIOU(words[i].back())) {
                ++ ans;
            }
        }
        return ans;
    }
};


int main() {
    test(&Solution::vowelStrings, {
    });
}