/* ***  METADATA
PROBLEM: sorting_and_searching_ferris_wheel__
ON: 2025-02-02
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
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    int count = 0;
    while (i <= j) {
        ll sum = a[i] + a[j];
        if (sum <= x) {
            i++;
        }
        j--;
        count++;
    }
    cout << count << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
