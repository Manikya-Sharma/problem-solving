/* ***
ON: 2025-03-18
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

void backtrack(int start, int node, vector<int>& parent, vector<int>& ans) {
    ans.push_back(node);
    if (node == start)
        return;
    backtrack(start, parent[node], parent, ans);
}

bool dfs(int node, vector<int>& parent, vector<bool>& visited,
         vector<vector<int>>& adj) {
    visited[node] = true;
    for (auto& nbr : adj[node]) {
        if (visited[nbr]) {
            if (parent[node] == nbr)
                continue;
            // cycle detected
            vector<int> ans;
            ans.push_back(nbr);
            backtrack(nbr, node, parent, ans);
            cout << sz(ans) << nl;
            for (int i = 0; i < sz(ans); i++) {
                cout << ans[i] + 1 << " \n"[i == sz(ans) - 1];
            }
            return true;
        }
        parent[nbr] = node;
        bool res = dfs(nbr, parent, visited, adj);
        if (res)
            return true;
    }
    return false;
}

void solution_fn() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a - 1, b - 1};
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        auto [a, b] = edges[i];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        found |= dfs(i, parent, visited, adj);
        if (found)
            break;
    }
    if (!found) {
        cout << "IMPOSSIBLE" << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

