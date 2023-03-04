#include "library.h"

/**
 * <a href="https://leetcode.cn/problems/find-duplicate-subtrees/">652. 寻找重复的子树</a>
 */

class Solution {
public:
    long i = 0;
    unordered_map<long, long> index;
    unordered_map<long, TreeNode*> record;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        record.clear();
        index.clear();
        dfs(root);
        vector<TreeNode*> ans;
        for (auto entry : record) {
            ans.push_back(entry.second);
        }
        return ans;
    }
    long dfs(TreeNode* root) {
        if (root== nullptr) return 0;
        long left = dfs(root->left), right = dfs(root->right);
        long code = (((left << 14) + right) << 9) + root->val;
        if (index.count(code) == 0) {
            return index[code] = ++i;
        } else {
            long idx = index[code];
            if (record.count(idx) == 0) record[idx] = root;
            return idx;
        }
    }
};



int main() {
    test(&Solution::findDuplicateSubtrees, {
            "[1,2,3,4,null,2,4,null,null,4]",
            "[2,1,1]",
            "[2,2,2,3,null,3,null]"
    });
}
