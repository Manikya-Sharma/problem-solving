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
        for (int j = i + 1; j < n; j++) {
            int req = x - a[i].first - a[j].first;
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                ll sum = a[k].first + a[l].first;
                if (sum > req) {
                    l--;
                } else if (sum < req) {
                    k++;
                } else {
                    cout << a[i].second << " " << a[j].second << " "
                         << a[k].second << " " << a[l].second << nl;
                    return;
                }
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
