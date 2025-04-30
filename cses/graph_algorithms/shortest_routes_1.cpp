/* ***
ON: 2025-03-19
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
    vector<vector<pair<ll, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }
    vector<ll> dist(n, 1e18);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [curr_d, node] = pq.top();
        pq.pop();
        if (curr_d > dist[node])
            continue;
        for (auto& [nbr, d] : adj[node]) {
            ll new_d = dist[node] + d;
            if (dist[nbr] > new_d) {
                dist[nbr] = new_d;
                pq.push({new_d, nbr});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
