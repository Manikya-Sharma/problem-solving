/* ***
ON: 2025-05-26
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dir(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                dir[i][j] = 1;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    dir[i][j] = 0;
                } else {
                    dp[i][j] = dp[i][j - 1];
                    dir[i][j] = 2;
                }
            }
        }
    }
    debug(dir);
    cout << dp[n][m] << nl;
    int i = n, j = m;
    vector<int> ans;
    while (i > 0 && j > 0) {
        if (dir[i][j] == 0) {
            i--;
        } else if (dir[i][j] == 1) {
            ans.push_back(a[i - 1]);
            i--;
            j--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int k = 0; k < sz(ans); k++) {
        cout << ans[k] << " \n"[k == sz(ans) - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
