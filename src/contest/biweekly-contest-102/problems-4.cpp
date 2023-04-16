#include "library.h"

class Graph {
    int n;
    vector<vector<int>> next, cost;
public:
    Graph(int n, vector<vector<int>> &edges) : n(n), next(n), cost(n, vector<int>(n, INT_MAX)) {
        for (auto &edge: edges) {
            addEdge(edge);
        }
    }

    void addEdge(vector<int> edge) {
        next[edge[0]].push_back(edge[1]);
        cost[edge[0]][edge[1]] = edge[2];
    }

    int shortestPath(int node1, int node2) {
        vector<int> ans(n, -1);
        using P = pair<int, int>;
        auto cmp = [&](P& i, P& j) {
            return i.second > j.second;
        };
        priority_queue<P, vector<P>, decltype(cmp)> q(cmp);
        q.emplace(node1, 0);
        while (!q.empty()) {
            P p = q.top();
            q.pop();
            int i = p.first;
            if (i == node2) return p.second;
            if (ans[i] >= 0) continue;
            ans[i] = p.second;
            for (int j: next[i]) {
                q.emplace(j, ans[i] + cost[i][j]);
            }
        }
        return -1;
    }
};


int main() {
//    test();
}