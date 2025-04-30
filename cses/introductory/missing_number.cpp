/* ***  METADATA

ON: 2025-01-27
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
    vi a(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int xxor =
        accumulate(a.begin(), a.end(), 0, [](int x, int y) { return x ^ y; });
    for (int i=1; i<=n; i++) {
        xxor ^= i;
    }
    cout << xxor << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
