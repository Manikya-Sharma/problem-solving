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
    vector<int> sieve(2e6, true);
    sieve[1] = false;
    for (int i = 2; i < 2e6; i++) {
        if (!sieve[i])
            continue;
        for (int j = i; i * 1ll * j < 2e6; j++) {
            sieve[i * j] = false;
        }
    }
    ll sum = 0;
    for (int i = 2; i < 2e6; i++) {
        sum += sieve[i] ? i : 0;
        if (i == 10) {
            debug(sum);
        }
    }
    cout << sum << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

