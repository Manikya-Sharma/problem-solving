/* ***
ON: 2025-03-24
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

#define INF (ll)(1e18)

void solution_fn() {
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {{a - 1, b - 1}, w};
    }

    vector<ll> dist(n, INF);
    vector<int> ancestor(n, -1);
    dist[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto& [node, w] : edges) {
            auto [a, b] = node;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                ancestor[b] = a;
            }
        }
    }

    for (auto& [node, w] : edges) {
        auto [a, b] = node;
        if (dist[a] + w < dist[b]) {
            ancestor[b] = a;
            int curr = a;
            for (int i = 0; i < n; i++) {
                curr = ancestor[curr];
            }
            vector<int> cycle;
            int start = curr;
            do {
                cycle.push_back(curr + 1);
                curr = ancestor[curr];
            } while (start != curr);
            cycle.push_back(curr + 1);
            reverse(cycle.begin(), cycle.end());
            cout << "YES" << nl;
            for (int i = 0; i < sz(cycle); i++) {
                cout << cycle[i] << " \n"[i == sz(cycle) - 1];
            }
            return;
        }
    }
    cout << "NO" << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

