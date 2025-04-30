/* ***  METADATA
PROBLEM: sorting_and_searching_stick_lengths__
ON: 2025-02-03
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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll cost1 = 0, cost2 = 0;
    int median1 = a[n / 2];
    int median2 = a[n / 2 - 1];
    for (auto& elem : a) {
        cost1 += abs(median1 - elem);
        cost2 += abs(median2 - elem);
    }
    cout << min(cost1, cost2) << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
