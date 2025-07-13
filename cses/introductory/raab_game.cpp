/* ***
ON: 2025-05-14
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
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n) {
        cout << "NO" << nl;
        return;
    }
    if (a == 0 && b == 0) {
        cout << "YES" << nl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " \n"[i == n - 1];
        }
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " \n"[i == n - 1];
        }
        return;
    }
    int fixed = n - (a + b);
    if (n - fixed == 1 || (a + n - fixed) % (n - fixed) == 0) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " \n"[i == n - 1];
    }
    for (int i = 0; i < n - fixed; i++) {
        cout << (i + a + (n - fixed)) % (n - fixed) + 1 << " \n"[i == n - 1];
    }
    for (int i = 0; i < fixed; i++) {
        cout << i + (n - fixed) + 1 << " \n"[i == fixed - 1];
    }
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
