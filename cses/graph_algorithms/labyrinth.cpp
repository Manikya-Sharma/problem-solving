/* ***
ON: 2025-03-11
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

pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
#define IN_BOUND(x, y, r, c) x >= 0 && y >= 0 && x < r&& y < c
char path_map[4] = {'U', 'R', 'D', 'L'};

void solution_fn() {
    int r, c;
    cin >> r >> c;
    vector<string> grid(r, string(c, '#'));
    pair<int, int> start, end;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char ch;
            cin >> ch;
            if (ch == 'A') {
                grid[i][j] = '.';
                start = {i, j};
            } else if (ch == 'B') {
                grid[i][j] = '.';
                end = {i, j};
            } else {
                grid[i][j] = ch;
            }
        }
    }
    vector<string> paths(r, string(c, '#'));
    queue<pair<int, int>> q;
    q.push(start);
    bool found = false;
    while (!q.empty()) {
        if (q.front() == end) {
            found = true;
            break;
        }
        auto [x, y] = q.front();
        q.pop();
        grid[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            auto [dx, dy] = dir[i];
            int new_x = x + dx;
            int new_y = y + dy;
            if (IN_BOUND(new_x, new_y, r, c) && grid[new_x][new_y] != '#' &&
                paths[new_x][new_y] == '#') {
                q.push({new_x, new_y});
                paths[new_x][new_y] = path_map[i];
            }
        }
    }
    if (!found) {
        cout << "NO" << nl;
        return;
    }
    string path;
    int x = end.first, y = end.second;
    while (paths[x][y] != '#') {
        char dirn = paths[x][y];
        path.push_back(dirn);
        if (dirn == 'L') {
            y++;
        } else if (dirn == 'R') {
            y--;
        } else if (dirn == 'U') {
            x++;
        } else {
            x--;
        }
    }
    reverse(path.begin(), path.end());
    cout << "YES" << nl;
    cout << sz(path) << nl;
    cout << path << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
