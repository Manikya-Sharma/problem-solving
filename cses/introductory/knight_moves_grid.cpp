/* ***
ON: 2025-06-29
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

#define IN_BOUND(n, x, y) (x >= 0 && y >= 0 && x < n && y < n)
void solution_fn() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 1e9));
    a[0][0] = 0;
    vector<pair<int, int>> del = {{-2, 1}, {2, 1},  {-2, -1}, {2, -1},
                                  {1, 2},  {1, -2}, {-1, 2},  {-1, -2}};
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    while (!q.empty()) {
        auto [d, pos] = q.front();
        q.pop();
        auto [x, y] = pos;
        for (auto &[dx, dy] : del) {
            int new_x = x + dx;
            int new_y = y + dy;
            if (IN_BOUND(n, new_x, new_y) && a[new_x][new_y] > d + 1) {
                a[new_x][new_y] = d + 1;
                q.push({d + 1, {new_x, new_y}});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " \n"[j == n - 1];
        }
    }
}
#undef IN_BOUND

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

