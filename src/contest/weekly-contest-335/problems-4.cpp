#include "library.h"

class Node {
private:
    vector<pair<Node*, int>> next;
    unordered_set<Node*> guess;
public:
    void add_edge(Node* n) {
        next.emplace_back(n, -1);
    }
    void add_guess(Node* n) {
        guess.insert(n);
    }
    int count(Node * pre = nullptr){
        int ans = 0;
        for (auto & p: next) {
            if (p.first==pre) continue;
            if (p.second < 0) p.second = p.first->count(this) + guess.count(p.first);
            ans += p.second;
        }
        return ans;
    }
};
class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        vector<Node*> nodes(edges.size()+1);
        for (auto & n: nodes) n = new Node();
        for (auto & e :edges) {
            nodes[e[0]]->add_edge(nodes[e[1]]);
            nodes[e[1]]->add_edge(nodes[e[0]]);
        }
        for (auto g: guesses) {
            nodes[g[0]]->add_guess(nodes[g[1]]);
        }
        int ans = 0;
        for (auto & n: nodes) if (n->count()>=k) ++ans;
        return ans;
    }
};


int main() {
    test(&Solution::rootCount, {
            "[[0,1],[1,2],[1,3],[4,2]] [[1,3],[0,1],[1,0],[2,4]] 3",
    });
}