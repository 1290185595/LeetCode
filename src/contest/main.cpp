//
// Created by Lenovo on 2023/2/18.
//
#include "library.h"
class Solution {
    vector<int> root;
    int get(int a) {
        if (root[a] == -1) return a;
        root[a] = get(root[a]);
        return root[a];
    }
    void merge(int a, int b) {
        a = get(a);
        b = get(b);
        if (a < b) root[b] = a;
        else if (a > b) root[a] = b;
    }
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        root = vector<int>(n, -1);
        vector<vector<bool>> diff(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            if (lcp[i][i] != n - i) return "";
            for (int j = 0; j < i; ++j) {
                if (lcp[i][j] != lcp[j][i]) return "";
                if (j > 0 && lcp[i-1][j-1] > 0 && lcp[i-1][j-1] - 1 != lcp[i][j]) return "";
                if (i + lcp[i][j] > n) return "";
                if (lcp[i][j] > 0) merge(i, j);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (lcp[i][i] > n - i) return "";
            for (int j = 0; j < i; ++j) {
                if (i + lcp[i][j] == n) continue;
                int a = get(i + lcp[i][j]), b = get(j + lcp[i][j]);
                if (a == b) return "";
                diff[a][b] = true;
            }
        }
        vector<int> used(26, -1);
        string ans;
        for (int i = 0; i < n; ++i) {
            if (get(i) != i) {
                ans.push_back(ans[get(i)]);
            } else {
                int j = 0;
                while (j < 26) {
                    if (used[j] == -1) {
                        used[j] = i;
                        break;
                    } else if (!diff[i][used[j]]) {
                        merge(i, used[j]);
                        break;
                    }
                    ++j;
                }
                if (j == 26) return "";
                ans.push_back((char)( 'a' + j));
            }
        }
        return ans;
    }
};
int main() {
    test (&Solution::findTheString, {
        "[[4,1,1,1],[1,3,1,1],[1,1,2,1],[1,1,1,1]]"
        });
}