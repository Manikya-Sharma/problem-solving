/* ***  METADATA

ON: 2025-02-16
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

int solve(int n) {
    if (n < 0)
        return 1e9;
    if (n == 0)
        return 0;
    int temp = n;
    int max_dig = 0;
    while (temp) {
        max_dig = max(max_dig, temp % 10);
        temp /= 10;
    }
    return 1 + solve(n - max_dig);
}

void solution_fn() {
    int n;
    cin >> n;
    cout << solve(n) << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
