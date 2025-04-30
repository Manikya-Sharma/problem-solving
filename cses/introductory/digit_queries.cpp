/* ***  METADATA
PROBLEM: llroductory_digit_queries__
ON: 2025-02-06
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) ll((x).size())
typedef vector<ll> vi;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

ll power(ll a, ll b) {
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
}

void solution_fn() {
    ll q;
    cin >> q;
    vector<ll> a(17);
    a[0] = 9;
    for (ll i = 2; i <= 17; i++) {
        a[i - 1] = a[i - 2] + 9 * power(10, i - 1) * i;
    }
    while (q--) {
        ll k;
        cin >> k;
        auto idx = lower_bound(a.begin(), a.end(), k) - a.begin();
        ll num_of_digits = (int)idx + 1;
        ll ub = power(10, num_of_digits) - 1;
        ll target = ub - (a[idx] - k) / num_of_digits;
        ll mod = (a[idx] - k) % num_of_digits;
        for (ll i = 0; i < mod; i++) {
            target /= 10;
        }
        debug(target);
        cout << target % 10 << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
