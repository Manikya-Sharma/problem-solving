/* ***  METADATA

ON: 2025-02-17
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
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int>(m + 2, 0));
    if (a[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][a[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % MOD +
                            dp[i - 1][j + 1]) %
                           MOD;
            }
        } else {
            dp[i][a[i]] = ((dp[i - 1][a[i] - 1] + dp[i - 1][a[i]]) % MOD +
                           dp[i - 1][a[i] + 1]) %
                          MOD;
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = (ans + dp[n - 1][j]) % MOD;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
