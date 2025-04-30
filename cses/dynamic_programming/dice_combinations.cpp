/* ***  METADATA

ON: 2025-02-14
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
    vi dp(n + 1);
    dp[0] = 1;
    for (int x = 1; x <= n; x++) {
        int ans = 0;
        for (int i = 1; i <= 6; i++) {
            if (x - i < 0)
                continue;
            ans = (ans + dp[x - i]) % MOD;
        }
        dp[x] = ans;
    }
    cout << dp[n] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
