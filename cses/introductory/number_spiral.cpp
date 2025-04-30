/* ***  METADATA

ON: 2025-01-28
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

ll solve(int x, int y) {
    int a = max(x, y);
    if (a % 2 == 0) {
        if (x <= y) {
            return (a - 1) * 1ll * (a - 1) + x;
        } else {
            return a * 1ll * a - y + 1;
        }
    } else {
        if (x <= y) {
            return a * 1ll * a - x + 1;
        } else {
            return (a - 1) * 1ll * (a - 1) + y;
        }
    }
}

void solution_fn() {
    int x, y;
    cin >> x >> y;
    cout << solve(x, y) << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solution_fn();
    }
    return 0;
}
