/* ***  METADATA
PROBLEM: sorting_and_searching_maximum_subarray_sum__
ON: 2025-02-02
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
    ll curr = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        curr += a[i];
        curr = max(curr, 0ll);
        ans = max(ans, curr);
    }
    if (ans == 0) {
        ans = -1e9;
        for (int i = 0; i < n; i++) {
            ans = max(ans, (ll)a[i]);
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
