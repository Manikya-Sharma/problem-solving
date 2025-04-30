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
    vector<ll> primes;
    set<ll> np;
    for (ll i = 2; i * i <= n; i++) {
        if (np.count(i))
            continue;
        primes.push_back(i);
        for (ll j = i; j * i < LONG_LONG_MAX / (j * i) && j * i * j * i <= n;
             j++) {
            np.insert(j * i);
        }
    }
    for (int i = sz(primes) - 1; i >= 0; i--) {
        auto elem = primes[i];
        if (n % elem == 0) {
            cout << elem << nl;
            return;
        }
    }
    assert(false);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
