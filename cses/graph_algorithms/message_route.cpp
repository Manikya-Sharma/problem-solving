/* ***
ON: 2025-03-15
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
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    vector<int> paths(n, -1);
    queue<int> q;
    q.push(n - 1);
    paths[n - 1] = 0;
    bool found = false;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node == 0) {
            found = true;
            break;
        }
        for (auto& nbr : adj[node]) {
            if (paths[nbr] == -1) {
                paths[nbr] = node;
                q.push(nbr);
            }
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    vector<int> path;
    path.push_back(1);
    int node = 0;
    while (node != n - 1) {
        path.push_back(paths[node]+1);
        node = paths[node];
    }
    cout << sz(path) << nl;
    for (int i = 0; i < sz(path); i++) {
        cout << path[i] << " \n"[i == sz(path) - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

