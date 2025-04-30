/* ***
ON: 2025-03-21
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> shortest_path(n, vector<ll>(n, 1e18));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        shortest_path[a - 1][b - 1] = min(shortest_path[a - 1][b - 1], (ll)c);
        shortest_path[b - 1][a - 1] = min(shortest_path[b - 1][a - 1], (ll)c);
    }

    for (int i=0; i<n; i++) {
        shortest_path[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (shortest_path[i][j] >
                    shortest_path[i][k] + shortest_path[k][j]) {
                    shortest_path[i][j] =
                        min(shortest_path[i][j],
                            shortest_path[i][k] + shortest_path[k][j]);
                }
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        auto ans = shortest_path[a - 1][b - 1];
        cout << (ans == (ll)1e18 ? -1 : ans) << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

