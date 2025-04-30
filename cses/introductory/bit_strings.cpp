/* ***  METADATA

ON: 2025-01-29
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
ll mod_exp(ll a, int b) {
    assert(b >= 0);
    if (b == 0) {
        assert(a != 0);
        return 1;
    }
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * 1ll * a) % MOD;
        b >>= 1;
    }
    return ans;
}

void solution_fn() {
    int n;
    cin >> n;
    cout << mod_exp(2, n) << nl;
}

int main() {
    solution_fn();
    return 0;
}
