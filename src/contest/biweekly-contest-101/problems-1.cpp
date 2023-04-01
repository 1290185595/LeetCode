#include "library.h"

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums(10, 0);
        for (int i: nums1) ++nums[i];
        sort(nums2.begin(), nums2.end());
        for (int i: nums2) {
            if (++nums[i] == 2) {
                return i;
            }
        }
        int v1= *min_element(nums1.begin(), nums1.end()), v2 = nums2[0];
        return v1 > v2 ? v2 * 10 + v1 : v1 * 10 + v2;
    }
};


int main() {
    test(&Solution::minNumber, {
            "[4,1,3] [5,7]",
    });
}