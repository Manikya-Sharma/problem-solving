/* ***  METADATA
PROBLEM: introductory_apple_division__
ON: 2025-01-31
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

void solve(vi& a, ll sum1, ll sum2, ll& min_diff, int idx) {
    int n = sz(a);
    if (idx == n) {
        min_diff = min(min_diff, abs(sum1 - sum2));
        return;
    }
    solve(a, sum1 + a[idx], sum2, min_diff, idx + 1);
    solve(a, sum1, sum2 + a[idx], min_diff, idx + 1);
}

void solution_fn() {
    int n;
    cin >> n;
    vi p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    ll min_diff = 1e9;
    solve(p, 0, 0, min_diff, 0);
    cout << min_diff << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
