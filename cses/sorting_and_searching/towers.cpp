/* ***  METADATA
PROBLEM: sorting_and_searching_towers__
ON: 2025-02-05
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
    vector<int> towers;
    for (auto& elem : a) {
        auto idx = upper_bound(towers.begin(), towers.end(), elem);
        if (idx == towers.end()) {
            towers.push_back(elem);
        } else {
            towers[idx - towers.begin()] = elem;
        }
    }
    cout << sz(towers) << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
