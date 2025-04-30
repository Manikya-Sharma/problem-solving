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
    sort(a.begin(), a.end());
    vector<int> prev(x + 1, 0);
    vector<int> curr(x + 1);

    for (int ii = 0; ii < n; ii++) {
        curr[0] = 1;
        for (int xx = 1; xx <= x; xx++) {
            int sol1 = ii == 0 ? 0 : prev[xx];
            int sol2 = xx - a[ii] < 0 ? 0 : curr[xx - a[ii]];
            curr[xx] = (sol1 + sol2) % MOD;
        }
        prev = curr;
    }

    cout << curr[x] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
