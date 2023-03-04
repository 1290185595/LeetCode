#include "library.h"

/**
 * <a href="https://leetcode.cn/problems/binary-tree-maximum-path-sum/">124. 二叉树中的最大路径和</a>
 */

class Solution {
private:
    int maxValue;
public:
    int maxPathSum(TreeNode *root) {
        maxValue = -1000;
        dfs(root);
        return maxValue;
    }

    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        maxValue = max(maxValue, root->val + left + right);
        return max(0, max(left, right) + root->val);
    }
};


int main() {
    test(&Solution::maxPathSum, {
        "[1,2,3]",
        "[-10,9,20,null,null,15,7]"
    });
}