/* ***
ON: 2025-03-19
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

#define IN_BOUND(x, y, r, c) (x >= 0 && y >= 0 && x < r && y < c)
vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
vector<char> path_map = {'U', 'L', 'D', 'R'};

void backtrack(vector<vector<char>>& path, pair<int, int> pos, string& ans,
               pair<int, int>& start) {
    if (pos == start)
        return;
    auto [x, y] = pos;
    ans.push_back(path[x][y]);
    if (path[x][y] == 'L') {
        backtrack(path, {x, y + 1}, ans, start);
    } else if (path[x][y] == 'R') {
        backtrack(path, {x, y - 1}, ans, start);
    } else if (path[x][y] == 'U') {
        backtrack(path, {x + 1, y}, ans, start);
    } else {
        backtrack(path, {x - 1, y}, ans, start);
    }
}

void solution_fn() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c, 1e9));
    vector<pair<int, int>> monsters;
    pair<int, int> start;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char ch;
            cin >> ch;
            if (ch == '#') {
                grid[i][j] = -1;
            } else if (ch == 'M') {
                monsters.push_back({i, j});
            } else if (ch == 'A') {
                start = {i, j};
            }
        }
    }
    queue<pair<int, pair<int, int>>> q;
    for (auto& pos : monsters) {
        q.push({0, pos});
    }
    while (!q.empty()) {
        auto [d, pos] = q.front();
        q.pop();
        grid[pos.first][pos.second] = d;
        for (auto& [dx, dy] : dir) {
            int new_x = pos.first + dx;
            int new_y = pos.second + dy;
            int new_d = d + 1;
            if (IN_BOUND(new_x, new_y, r, c) && grid[new_x][new_y] > new_d) {
                grid[new_x][new_y] = new_d;
                q.push({new_d, {new_x, new_y}});
            }
        }
    }
    vector<vector<char>> path(r, vector<char>(c, '#'));
    q.push({0, start});
    bool found = false;
    while (!q.empty()) {
        auto [d, pos] = q.front();
        q.pop();
        if (pos.first == 0 || pos.first == r - 1 || pos.second == 0 ||
            pos.second == c - 1) {
            found = true;
            string ans;
            backtrack(path, pos, ans, start);
            reverse(ans.begin(), ans.end());
            cout << "YES" << nl;
            cout << sz(ans) << nl;
            cout << ans << nl;
            break;
        }
        for (int i = 0; i < 4; i++) {
            auto [dx, dy] = dir[i];
            auto ch = path_map[i];
            int new_x = pos.first + dx;
            int new_y = pos.second + dy;
            int new_d = d + 1;
            if (IN_BOUND(new_x, new_y, r, c) && grid[new_x][new_y] > new_d &&
                path[new_x][new_y] == '#') {
                path[new_x][new_y] = ch;
                grid[new_x][new_y] = new_d;
                q.push({new_d, {new_x, new_y}});
            }
        }
    }
    if (!found) {
        cout << "NO" << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

