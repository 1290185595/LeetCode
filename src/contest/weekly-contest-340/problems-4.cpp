#include "library.h"

class Node {
public:
    bool used;
    int row, col, maxI, maxJ;
    Node *row_next, *col_next;

    Node(int i, int j, int v, Node *row_next, Node *col_next) : used(false), row(i), col(j), maxI(i + v), maxJ(j + v),
                                                                row_next(row_next), col_next(col_next) {}

    Node *get_row_next() {
        if ((row_next != nullptr) && row_next->used) row_next = row_next->get_row_next();
        return row_next;
    }

    Node *get_col_next() {
        if ((col_next != nullptr) && col_next->used) col_next = col_next->get_col_next();
        return col_next;
    }

    Node *erase() {
        this->used = true;
        return this;
    }
};

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<Node *>> nodes(m--+1, vector<Node *>(n--+1, nullptr));
        for (int i = m; i >= 0; --i)
            for (int j = n; j >= 0; --j)
                nodes[i][j] = new Node(i, j,grid[i][j], nodes[i + 1][j], nodes[i][j + 1]);

        queue<Node *> q;
        q.push(nodes[0][0]->erase());
        for (int step = 1; !q.empty(); ++step) {
            for (int size = q.size(); size > 0; --size) {
                Node *cur = q.front();
                if ((cur->row == m) && cur->col == n) return step;
                q.pop();
                Node *p;
                while (((p=cur->get_row_next()) != nullptr) && (p->row<=cur->maxI)) q.push(p->erase());
                while (((p=cur->get_col_next()) != nullptr) && (p->col<=cur->maxJ)) q.push(p->erase());
            }
        }
        return -1;
    }
};


int main() {
    test(&Solution::minimumVisitedCells, {
            "[[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]",
    });
}