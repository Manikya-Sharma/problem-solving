/* *** PROBLEM: project_euler_1_multiples_of_3_or_5
ON: 2025-03-10
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
    n--;
    ll c1 = n / 3;
    ll sum1 = c1 * (2 * 3ll + (c1 - 1) * 3) / 2;
    ll c2 = n / 5;
    ll sum2 = c2 * (2 * 5ll + (c2 - 1) * 5) / 2;
    ll c3 = n / 15;
    ll sum3 = c3 * (2 * 15ll + (c3 - 1) * 15) / 2;
    cout << sum1 + sum2 - sum3 << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
