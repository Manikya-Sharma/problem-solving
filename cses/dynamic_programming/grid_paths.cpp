/* ***  METADATA

ON: 2025-02-16
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */
#define MOD (int)(1e9 + 7)

void solution_fn() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    if (grid[n-1][n-1] == '*') {
        cout << 0 << nl;
        return;
    }
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)
                continue;
            int up = (i == 0 || grid[i - 1][j] == '*') ? 0 : dp[i - 1][j];
            int left = (j == 0 || grid[i][j - 1] == '*') ? 0 : dp[i][j - 1];
            dp[i][j] = (up + left) % MOD;
        }
    }
    cout << dp[n - 1][n - 1] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
