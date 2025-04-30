/* ***
ON: 2025-04-27
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
    string s;
    cin >> s;
    int n = sz(s);
    ll ans = 0;
    for (int i = 0; i < n - 12; i++) {
        ll prod = 1;
        for (int j = 0; j < 13; j++) {
            prod *= s[i + j] - '0';
        }
        ans = max(ans, prod);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

