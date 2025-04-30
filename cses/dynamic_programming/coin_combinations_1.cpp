/* ***  METADATA

ON: 2025-02-15
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
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi dp(x + 1, 0);
    dp[0] = 1;
    for (int xx = 1; xx <= x; xx++) {
        int sum = 0;
        for (auto& elem : a) {
            if (xx - elem < 0)
                continue;
            sum = (sum + dp[xx - elem]) % MOD;
        }
        dp[xx] = sum;
    }
    cout << dp[x] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
