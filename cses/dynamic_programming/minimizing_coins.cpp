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
#define INF (int)(1e9)

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

void solution_fn() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> curr(x + 1, INF);
    vector<int> prev(x + 1, INF);
    prev[0] = 0;
    for (int ii = 1; ii <= n; ii++) {
        curr[0] = 0;
        for (int xx = 1; xx <= x; xx++) {
            if (a[ii - 1] > xx) {
                curr[xx] = prev[xx];
                continue;
            }
            int sol1 = prev[xx];
            int sol2 = curr[xx - a[ii - 1]] + 1;
            curr[xx] = min(sol1, sol2);
        }
        prev = curr;
    }
    int ans = prev[x] == INF ? -1 : prev[x];
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
