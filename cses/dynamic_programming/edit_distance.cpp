/* ***  METADATA

ON: 2025-02-19
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

void solution_fn() {
    string a, b;
    cin >> a >> b;
    int n1 = sz(a), n2 = sz(b);

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
    for (int i = 0; i <= n1; i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= n2; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(min(1 + dp[i - 1][j], 1 + dp[i][j - 1]),
                               1 + dp[i - 1][j - 1]);
            }
        }
    }
    cout << dp[n1][n2] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
