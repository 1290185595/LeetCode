#include "library.h"

class Solution {
public:
    int challengeOfTheKeeper(vector<string>& maze) {
        using pInt = pair<int, int>;
        int n = maze.size();
        vector<vector<int>> step0(n, vector<int>(n, -1));
        queue<pInt> q;
        pInt s, t;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (maze[i][j] == 'S') {
                    s = {i, j};
                } else if (maze[i][j] == 'T') {
                    t = {i, j};
                    q.push(t);
                    step0[i][j] = 0;
                }
            }
        }
        auto check0 = [&](int i, int j) {
            if ((i < 0) || (j < 0) || (i >= n) || (j >= n)) return false;
            return (maze[i][j]!='#') && (step0[i][j] < 0);
        };
        for (int i = 1; !q.empty(); ++i) {
            for (int j = q.size(); j > 0; --j) {
                pInt p = q.front();
                q.pop();
                if (check0(p.first-1, p.second)) {
                    q.emplace(p.first-1,p.second);
                    step0[p.first-1][p.second] = i;
                }
                if (check0(p.first+1, p.second)) {
                    q.emplace(p.first+1,p.second);
                    step0[p.first+1][p.second] = i;
                }
                if (check0(p.first, p.second-1)) {
                    q.emplace(p.first,p.second-1);
                    step0[p.first][p.second-1] = i;
                }
                if (check0(p.first, p.second+1)) {
                    q.emplace(p.first,p.second+1);
                    step0[p.first][p.second+1] = i;
                }
            }
        }
        vector<vector<bool>> viewed(n, vector<bool>(n, false));
        auto cmp = [&](pair<int, pInt>& a, pair<int, pInt>& b){return a.first > b.first;};
        priority_queue<pair<int, pInt>, vector<pair<int, pInt>>, decltype(cmp)> go(cmp);
        viewed[s.first][s.second] = true;
        go.emplace(0, s);
        auto next_step= [&](int i, int j) {
            if ((i < 0) || (j < 0) || (i >= n) || (j >= n) || viewed[i][j]) return -1;
            viewed[i][j] = true;
            if (maze[i][j]=='#') return -1;
            if (maze[i][j] == 'T') return 0;
            int ans = 0;
            if (maze[n-1-i][j]!='#') {
                if (step0[n-1-i][j] == -1) return -1;
                ans = max(ans, step0[n-1-i][j]);
            }
            if (maze[i][n-1-j]!='#') {
                if (step0[i][n-1-j] == -1) return -1;
                ans = max(ans, step0[i][n-1-j]);
            }
            return ans;
        };
        while (!go.empty()) {
            auto [step, p] = go.top();
            go.pop();
            if (p == t) return step;
            if (int i = next_step(p.first-1,p.second); i != -1) go.emplace(max(step, i), make_pair(p.first-1,p.second));
            if (int i = next_step(p.first+1,p.second); i != -1) go.emplace(max(step, i), make_pair(p.first+1,p.second));
            if (int i = next_step(p.first,p.second-1); i != -1) go.emplace(max(step, i), make_pair(p.first,p.second-1));
            if (int i = next_step(p.first,p.second+1); i != -1) go.emplace(max(step, i), make_pair(p.first,p.second+1));
        }
        return -1;
    }
};


int main() {
    test(&Solution::challengeOfTheKeeper, {
            "[.......#.....#..#####.###..#.#..#.....##...,#..#......#.................#.....#.##....#,..#...........#........#.##.##.....#.#.....,.......####.#.........##.......#..#........,.#........#....##............#.......#.....,......##.......#.......#.#...#...##........,..#...#....#.....##...#...###....#.#..#....,.......#..#..........#...#...#####.......##,......#..#.#...#...........#....#....#..#..,....#....##...##..#........#.....#...#.....,#...........#....#.#.#..............#...##.,#.#.#..#T...##........####.#...#......#....,..###....##.#.....#........#...#....#..S.#.,..#......#.#...##.....##.#..#............##,#.....#.#...#.........#....##..#..#.#......,#..#..#.##.#.....##.......#......#...#...#.,##......#....#...##.#......#.##........##..,.......#..#...#......#......#.....#..#.....,.....#...#.##.##..........#..#..#...#..#...,....#...###..........#.###.#.##............,....#.##.#......##.#.....#...#.......#.#...,.....#.#.........#...#........#....#.#..#..,.....#.#......#..##..#........#....#.#.....,.....#........#.......#.#...#..............,#...##.##......#.....#.#.#.....#........#.#,........#.#....#..###.#.........#.......###,#....###.....##....#.#....#.#.#........#..#,....#...##....##..#....#..........##..#....,...#...........#..#.....#..#.#..#........#.,..##.#.......#.#.#..##.........#.#...##....,.##.#...##.##.#.##....#...##....#..........,##......##...#.#.....#..#..###.#....#....#.,............#.....#......##..#..###..#...#.,.......##...#..#...#......#.#..##...##...#.,#..##..##.............#.###.#..#.#.#..#.###,...#..#......##..#..#.........#.........#.#,......##.....#.....###.......#.#..#...#....,##.#.#...##..#.#.#...#.........#........###,....#.#.........#.#....####................,..##..##.....#...#...##......#.#.......#...,#.###....#..##....#.....#....####..#....#..,.#.......#........#....##..#...#..##.......,......#..........##...##..##.......#.......]",
    });
}