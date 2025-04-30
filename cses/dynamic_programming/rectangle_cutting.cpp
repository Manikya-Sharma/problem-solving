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

int solve(int a, int b, vector<vector<int>>& dp) {
    if (a == b)
        return 0;
    if (dp[a][b] != -1)
        return dp[a][b];
    int ans = 1e9;
    for (int k = 1; k < a; k++) {
        ans = min(ans, 1 + solve(a - k, b, dp) + solve(k, b, dp));
    }
    for (int k = 1; k < b; k++) {
        ans = min(ans, 1 + solve(a, b - k, dp) + solve(a, k, dp));
    }
    return dp[a][b] = ans;
}

void solution_fn() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1));

    for (int i = 0; i <= min(a, b); i++) {
        dp[i][i] = 0;
    }

    for (int aa = 0; aa <= a; aa++) {
        for (int bb = 0; bb <= b; bb++) {
            if (aa == bb)
                continue;
            int ans = 1e9;
            for (int k = 1; k < aa; k++) {
                ans = min(ans, 1 + dp[aa - k][bb] + dp[k][bb]);
            }
            for (int k = 1; k < bb; k++) {
                ans = min(ans, 1 + dp[aa][bb - k] + dp[aa][k]);
            }
            dp[aa][bb] = ans;
        }
    }

    cout << dp[a][b] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
