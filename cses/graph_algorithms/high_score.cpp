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
    vector<pair<pair<int, int>, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {{a - 1, b - 1}, c};
    }
    vector<ll> dist(n, -1e18);
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto& [node, w] : edges) {
            auto [a, b] = node;
            if (dist[a] + w > dist[b]) {
                dist[b] = dist[a] + w;
            }
        }
    }
    vector<bool> cycle(n, false);
    for (auto& [node, w] : edges) {
        auto [a, b] = node;
        if (dist[a] + w > dist[b]) {
            cycle[b] = true;
        }
    }
    vector<vector<int>> rev_adj(n);
    vector<vector<int>> adj(n);
    for (auto& [node, _] : edges) {
        auto [a, b] = node;
        rev_adj[b].push_back(a);
        adj[a].push_back(b);
    }
    vector<bool> a_reachable(n, false);
    queue<int> q;
    q.push(0);
    a_reachable[0] = true;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (auto& nbr : adj[node]) {
            if (a_reachable[nbr])
                continue;
            a_reachable[nbr] = true;
            q.push(nbr);
        }
    }
    q.push(n - 1);
    bool has_cycle = false;
    vector<bool> visited(n, false);
    visited[n - 1] = true;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (cycle[node] && a_reachable[node]) {
            has_cycle = true;
            break;
        }
        for (auto& nbr : rev_adj[node]) {
            if (visited[nbr])
                continue;
            visited[nbr] = true;
            q.push(nbr);
        }
    }
    if (has_cycle) {
        cout << -1 << nl;
    } else {
        cout << dist[n - 1] << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

