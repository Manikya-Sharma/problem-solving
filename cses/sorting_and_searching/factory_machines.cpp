/* ***  METADATA

ON: 2025-02-11
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

bool is_possible(vi a, ll mid, int t) {
    ll count = 0;
    for (auto& elem : a) {
        if (count >= LONG_LONG_MAX - mid / elem)
            return true;
        count += mid / elem;
    }
    return count >= t;
}

void solution_fn() {
    int n, t;
    cin >> n >> t;
    vi a(n);
    int max_elem = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_elem = max(max_elem, a[i]);
    }
    ll start = 1, end = t * 1ll * max_elem;
    while (start <= end) {
        ll mid = start + (end - start) / 2;
        if (is_possible(a, mid, t)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    cout << start << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
