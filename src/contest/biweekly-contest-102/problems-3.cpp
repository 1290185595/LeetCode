#include "library.h"

class Solution {
    vector<int> sum;

    void get_sum(TreeNode *root, int deep = 0) {
        if (root == nullptr) return;
        if (sum.size() == deep) sum.push_back(root->val);
        else sum[deep] += root->val;
        get_sum(root->left, deep + 1);
        get_sum(root->right, deep + 1);
    }

    int get_val(TreeNode *root) {
        return root == nullptr ? 0 : root->val;
    }

    void get_sub(TreeNode *root, int val, int deep = 0) {
        if (root == nullptr) return;
        root->val = sum[deep] - val;
        val = get_val(root->left) + get_val(root->right);
        get_sub(root->left, val, deep + 1);
        get_sub(root->right, val, deep + 1);
    }

public:
    TreeNode *replaceValueInTree(TreeNode *root) {
        sum.clear();
        get_sum(root);
        get_sub(root, root->val);
        return root;
    }
};


int main() {
    test(&Solution::replaceValueInTree, {

    });
}