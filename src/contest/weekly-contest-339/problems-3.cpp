#include "library.h"

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        transform(reward1.begin(), reward1.end(), reward2.begin(), reward1.begin(), minus());
        sort(reward1.begin(),reward1.end(), greater());
        return accumulate(reward1.begin(), reward1.begin()+k, 0) + accumulate(reward2.begin(), reward2.end(),0);
    }
};


int main() {
    test(&Solution::miceAndCheese, {
            "[1,1,3,4] [4,4,1,1] 2",
    });
}