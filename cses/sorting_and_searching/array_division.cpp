/* ***  METADATA

ON: 2025-02-12
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

bool is_possible(vi& a, ll mid, int k) {
    ll curr = 0;
    int count = 1;
    for (int i = 0; i < sz(a); i++) {
        curr += a[i];
        if (curr > mid) {
            curr = a[i];
            if (curr > mid)
                return false;
            count++;
        }
    }
    return count <= k;
}

void solution_fn() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll start = 0;
    ll end = LONG_LONG_MAX;
    while (start <= end) {
        ll mid = start + (end - start) / 2;
        if (is_possible(a, mid, k)) {
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
