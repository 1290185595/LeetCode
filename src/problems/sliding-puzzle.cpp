#include "library.h"

/**
 * <a href="https://leetcode.cn/problems/sliding-puzzle/">773. 滑动谜题</a>
 */

class Solution {
public:
    unsigned int vec2Int(vector<vector<int>> const & board) {
        int ans = 0, temp;
        for (int i = 1; i >=0; --i) {
            for (int j = 2; j >=0; --j) {
                int v = board[i][j];
                ans <<= 3;
                ans += v;
                if (v == 0) temp = (i << 2) + j;
            }
        }
        return (ans << 4) + temp;
    }
    unsigned int swap(unsigned int value, int row, int col, int deltaRow, int deltaCol) {
        int newRow = row + deltaRow, newCol = col + deltaCol;
        if (newRow < 0 || newRow > 1 || newCol < 0 || newCol > 2) return 0;
        int x = (row * 3 + col) * 3, y = (newRow * 3 + newCol) * 3;
        unsigned int mask = ~((0b111 << x) + (0b111 << y)), temp = ((value >> x & 0b111) << y) + ((value >> y & 0b111) << x);
        return (((((value & mask) + temp) << 2) + newRow) << 2) + newCol;
    }
    bool check(unsigned int value, unsigned int target, queue<unsigned int> & q, unordered_set<unsigned int> & viewed) {
        if (value == target) return true;
        else if (value > 0 && viewed.count(value) == 0) {
            q.push(value);
            viewed.insert(value);
        }
        return false;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        unsigned int target = vec2Int({{1,2,3},{4,5,0}}), start = vec2Int(board);
        if (start == target) return 0;
        unordered_set<unsigned int> viewed = {0, start};
        queue<unsigned int> q;
        q.push(start);
        for (int i = 1; !q.empty(); ++i) {
            for (int j = q.size(); j > 0; --j) {
                int value = q.front();
                q.pop();
                int col = value & 0b11;
                value >>= 2;
                int row = value & 0b11;
                value >>= 2;
                if (check(swap(value, row, col, 0, -1), target, q, viewed)) return i;
                if (check(swap(value, row, col, 0, +1), target, q, viewed)) return i;
                if (check(swap(value, row, col, -1, 0), target, q, viewed)) return i;
                if (check(swap(value, row, col, +1, 0), target, q, viewed)) return i;
            }
        }
        return -1;
    }
};

int main() {
    test(&Solution::slidingPuzzle, {
            "[[1,2,3],[4,0,5]]"
    });
}
