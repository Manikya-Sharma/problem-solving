/* ***
ON: 2025-03-23
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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(2 * n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a - 1].push_back({b - 1, w});
        adj[a - 1].push_back({b + n - 1, w / 2});
        adj[a + n - 1].push_back({b + n - 1, w});
    }
    adj[n - 1].push_back({2 * n, 0});
    adj[2 * n - 1].push_back({2 * n, 0});
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        pq;
    pq.push({0, 0});
    vector<ll> dist(2 * n + 1, 1e18);
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (d > dist[node])
            continue;
        for (auto& [nbr, nbr_d] : adj[node]) {
            ll new_d = nbr_d + d;
            if (new_d < dist[nbr]) {
                dist[nbr] = new_d;
                pq.push({new_d, nbr});
            }
        }
    }
    cout << dist[2 * n] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

