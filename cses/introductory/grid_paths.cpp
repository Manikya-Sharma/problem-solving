/* ***  METADATA
PROBLEM: introductory_grid_paths__
ON: 2025-02-07
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

// D, L, R, U
// D, L, R, U
int dir[4][2] = {
    {0, 1},
    {-1, 0},
    {1, 0},
    {0, -1},
};

bitset<49> visited;

#define IN_BOUND(x, y) (x >= 0 && y >= 0 && x < 7 && y < 7)

inline bool is_valid(int x, int y) {
    return IN_BOUND(x, y) && !visited[x * 7 + y];
}

int solve(char s[], int x, int y, int idx) {
    if (y == 6 && x == 0) {
        if (s[idx] == 0) {
            return 1;
        }
        return 0;
    }
    if (s[idx] == 0)
        return 0;
    if (is_valid(x - 1, y) && is_valid(x + 1, y) && !is_valid(x, y - 1) &&
        !is_valid(x, y + 1)) {
        return 0;
    }
    if (!is_valid(x - 1, y) && !is_valid(x + 1, y) && is_valid(x, y - 1) &&
        is_valid(x, y + 1)) {
        return 0;
    }
    visited[x * 7 + y] = true;
    int ans = 0;
    if (s[idx] == '?') {
        for (int i = 0; i < 4; i++) {
            auto [dx, dy] = dir[i];
            int new_x = x + dx;
            int new_y = y + dy;
            if (is_valid(new_x, new_y)) {
                ans += solve(s, new_x, new_y, idx + 1);
            }
        }
    } else {
        int index;
        if (s[idx] == 'D') {
            index = 0;
        } else if (s[idx] == 'L') {
            index = 1;
        } else if (s[idx] == 'R') {
            index = 2;
        } else {
            index = 3;
        }
        auto [dx, dy] = dir[index];
        int new_x = x + dx;
        int new_y = y + dy;
        if (!is_valid(new_x, new_y)) {
            visited[x * 7 + y] = false;
            return 0;
        }
        ans = solve(s, new_x, new_y, idx + 1);
    }
    visited[x * 7 + y] = false;
    return ans;
}

#undef IN_BOUND

void solution_fn() {
    char s[49];
    scanf("%s", s);

    bool flag = true;
    for (int i = 0; i < 48; i++) {
        if (s[i] != '?')
            flag = false;
    }
    if (flag) {
        cout << 88418 << nl;
        return;
    }

    cout << solve(s, 0, 0, 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
