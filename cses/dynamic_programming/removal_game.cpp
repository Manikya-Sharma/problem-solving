/* ***
ON: 2025-03-09
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

/*
dp[i][j] = max difference in score for player 1 in range i..j
therefore, dp[i][i] = arr[i] \forall i

and dp[i][j] = max(dif1, dif2)
where dif1 = arr[i] - dp[i+1][j]
  and dif2 = arr[j] - dp[i][j-1]
*/

void solution_fn() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            ll ans = -1e18;
            if (j > 0) {
                ans = max(ans, a[j] - dp[i][j - 1]);
            }
            if (i < n - 1) {
                ans = max(ans, a[i] - dp[i + 1][j]);
            }
            dp[i][j] = ans;
        }
    }
    ll diff = dp[0][n - 1];
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    ll ans = (sum + diff) / 2;
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
