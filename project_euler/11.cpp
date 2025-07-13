/* ***
ON: 2025-05-19
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

void solution_fn() {
    int n = 20;
    vector<vector<ll>> grid(20, vector<ll>(20));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < n - 4 && j < n - 4) {
                ll prod = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] *
                          grid[i + 3][j + 3];
                ans = max(ans, prod);
            }
            if (i < n - 4) {
                ans = max(ans, grid[i][j] * grid[i + 1][j] * grid[i + 2][j] *
                                   grid[i + 3][j]);
            }
            if (j < n - 4) {
                ans = max(ans, grid[i][j] * grid[i][j + 1] * grid[i][j + 2] *
                                   grid[i][j + 3]);
            }
            if (i >= 3 && j < n - 4) {
                ll prod = grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] *
                          grid[i - 3][j + 3];
                ans = max(ans, prod);
            }
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

