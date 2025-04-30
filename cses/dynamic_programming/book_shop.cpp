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

void solution_fn() {
    int n, x;
    cin >> n >> x;
    // price -> pages
    vector<pair<int, int>> vpi(n);
    for (int i = 0; i < n; i++) {
        cin >> vpi[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> vpi[i].second;
    }
    vector<int> prev(x + 1, 0);
    vector<int> curr(x + 1);
    for (int idx = 0; idx < n; idx++) {
        curr[0] = 0;
        for (int money = 1; money <= x; money++) {
            curr[money] =
                max(prev[money],
                    money < vpi[idx].first
                        ? 0
                        : vpi[idx].second + prev[money - vpi[idx].first]);
        }
        prev = curr;
    }

    cout << curr[x] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
