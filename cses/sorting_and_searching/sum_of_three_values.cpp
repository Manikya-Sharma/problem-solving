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

void solution_fn() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        a[i] = {elem, i + 1};
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int req = x - a[i].first;
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            ll sum = a[j].first + a[k].first;
            if (sum > req) {
                k--;
            } else if (sum < req) {
                j++;
            } else {
                cout << a[i].second << " " << a[j].second << " " << a[k].second
                     << nl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
