/* ***  METADATA

ON: 2025-01-30
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
    int a, b;
    cin >> a >> b;
    if (a < b)
        swap(a, b);
    int diff = a - b;
    if (diff > b) {
        cout << "NO" << nl;
        return;
    }
    if ((a + b) % 3 != 0) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
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
