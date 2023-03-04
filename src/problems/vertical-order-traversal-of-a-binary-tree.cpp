#include "library.h"

/**
 * <a href="https://leetcode.cn/problems/vertical-order-traversal-of-a-binary-tree/">987. 二叉树的垂序遍历</a>
 */

class Solution {
private:
    unordered_map<int, vector<int>> m;
    int minValue,maxValue;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        m.clear();
        minValue = 1;
        maxValue = 0;
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        int mask = (1 << 10) -1;
        for (int i = minValue; i <= maxValue; ++i) {
            vector<int> & temp = m[i];
            sort(temp.begin(), temp.end());
            for (auto p = temp.begin(); p < temp.end(); ++p) {
                *p &= mask;
            }
            ans.push_back(temp);
        }
        return ans;
    }
    void dfs(TreeNode* root, int row, int col) {
        if (root == nullptr) return;
        if (m.count(col) == 0) {
            m[col] = {};
            if (col < minValue) minValue = col;
            else maxValue = col;
        }
        m[col].push_back((row++ << 10) + root->val);
        dfs(root->left, row, col-1);
        dfs(root->right,  row, col+1);
    }
};
//extern int a();
int main() {
    a();
    test(&Solution::verticalTraversal, {
            "[3,9,20,null,null,15,7]",
            "[1,2,3,4,5,6,7]",
            "[1,2,3,4,6,5,7]",
    });
}
