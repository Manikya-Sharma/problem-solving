/* ***
ON: 2025-03-30
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

bool dfs(vector<vector<int>>& adj, int node, vector<int>& parent,
         vector<bool>& visited) {
    if (visited[node]) {
        vector<int> path;
        int temp = node;
        do {
            if (node == -1)
                return false;
            path.push_back(node);
            node = parent[node];
        } while (node != temp);
        path.push_back(path[0]);
        cout << sz(path) << nl;
        reverse(path.begin(), path.end());
        for (int i = 0; i < sz(path); i++) {
            cout << path[i] + 1 << " \n"[i == sz(path) - 1];
        }
        return true;
    }
    visited[node] = true;
    for (auto& nbr : adj[node]) {
        parent[nbr] = node;
        bool res = dfs(adj, nbr, parent, visited);
        if (res)
            return true;
    }
    return false;
}

void solution_fn() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        bool res = dfs(adj, i, parent, visited);
        if (res) {
            return;
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
