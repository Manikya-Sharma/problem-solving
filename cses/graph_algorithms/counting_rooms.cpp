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

#define IN_BOUND(x, y, grid) x >= 0 && y >= 0 && x < sz(grid) && y < sz(grid[0])

vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(vector<string>& grid, vector<vector<bool>>& visited, int x, int y) {
    visited[x][y] = true;
    for (auto& [dx, dy] : dir) {
        int new_x = x + dx;
        int new_y = y + dy;
        if (IN_BOUND(new_x, new_y, grid) && !visited[new_x][new_y] &&
            grid[new_x][new_y] == '.') {
            dfs(grid, visited, new_x, new_y);
        }
    }
}

void solution_fn() {
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }
    int count = 0;
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visited[i][j] || grid[i][j] == '#')
                continue;
            dfs(grid, visited, i, j);
            count++;
        }
    }
    cout << count << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

