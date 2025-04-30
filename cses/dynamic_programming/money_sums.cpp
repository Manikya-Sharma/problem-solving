/* ***  METADATA

ON: 2025-02-20
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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int sum = accumulate(a.begin(), a.end(), 0);
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= sum; s++) {
            if (dp[i - 1][s]) {
                dp[i][s] = true;
            } else if (s - a[i - 1] >= 0 && dp[i - 1][s - a[i - 1]]) {
                dp[i][s] = true;
            }
        }
    }
    vi ans;
    for (int i = 1; i <= sum; i++) {
        if (dp[n][i]) {
            ans.push_back(i);
        }
    }
    cout << sz(ans) << nl;
    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] << " \n"[i == sz(ans) - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
