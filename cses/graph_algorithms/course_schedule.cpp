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

void solution_fn() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a - 1, b - 1};
    }
    vector<int> indegree(n, 0);
    vector<vector<int>> adj(n);
    for (auto& [x, y] : edges) {
        indegree[y]++;
        adj[x].push_back(y);
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto& nbr : adj[node]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
    if (sz(ans) != n) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

