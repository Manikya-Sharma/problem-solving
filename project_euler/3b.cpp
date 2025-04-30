/* *** PROBLEM: project_euler_3_largest_prime_factor
ON: 2025-03-14
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
    ll n;
    cin >> n;
    vector<int> smallest_pf(n + 1, -1);
    // prepare sieve
    for (int i = 2; i <= n; i++) {
        if (smallest_pf[i] != -1)
            continue;
        for (int j = i; i * 1ll * j <= n; j++) {
            if (smallest_pf[i * 1ll * j] == -1)
                smallest_pf[i * 1ll * j] = i;
        }
    }
    // determine largest pf
    while (smallest_pf[n] != -1) {
        n = n / smallest_pf[n];
    }
    cout << n << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

