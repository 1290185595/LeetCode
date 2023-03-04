#include "library.h"

class Solution {
public:
    int closeLampInTree(TreeNode* root) {
        return dfs(root)[0];
    }
    vector<int> dfs(TreeNode* root) {
        if (root == nullptr) return vector<int> (4, 0);
        vector<int> left = dfs(root->left), right = dfs(root->right);
        vector<int> ans;
        if (root->val == 0) {
            ans.emplace_back(min(left[0]+right[0], min(left[1]+right[1]+2, min(left[2]+right[2]+2, left[3]+right[3]+2))));
            ans.emplace_back(min(left[0]+right[0]+1, min(left[1]+right[1]+1, min(left[2]+right[2]+1, left[3]+right[3]+3))));
            ans.emplace_back(min(left[0]+right[0]+2, min(left[1]+right[1], min(left[2]+right[2]+2, left[3]+right[3]+2))));
            ans.emplace_back(min(left[0]+right[0]+1, min(left[1]+right[1]+1, min(left[2]+right[2]+3, left[3]+right[3]+1))));
        } else {
            ans.emplace_back(min(left[0]+right[0]+1, min(left[1]+right[1]+1, min(left[2]+right[2]+3, left[3]+right[3]+1))));
            ans.emplace_back(min(left[0]+right[0]+2, min(left[1]+right[1], min(left[2]+right[2]+2, left[3]+right[3]+2))));
            ans.emplace_back(min(left[0]+right[0]+1, min(left[1]+right[1]+1, min(left[2]+right[2]+1, left[3]+right[3]+3))));
            ans.emplace_back(min(left[0]+right[0], min(left[1]+right[1]+2, min(left[2]+right[2]+2, left[3]+right[3]+2))));
        }
        return ans;
    }
};


int main() {
    test(&Solution::closeLampInTree, {
        "[1,1,0,null,null,null,1]"
    });
}