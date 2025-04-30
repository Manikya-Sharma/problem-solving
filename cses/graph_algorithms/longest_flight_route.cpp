/* ***
ON: 2025-04-02
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

    vector<vector<int>> rev_adj(n);
    for (auto& [x, y] : edges) {
        rev_adj[y].push_back(x);
    }

    vector<int> dp(n, 0);
    dp[n - 1] = 1;
    queue<int> q;
    q.push(n - 1);

    vector<int> parent(n, -1);

    bool found = false;
    while (!q.empty()) {
        auto node = q.front();
        if (node == 0) {
            found = true;
            break;
        }
        q.pop();
        for (auto& nbr : rev_adj[node]) {
            if (1 + dp[node] > dp[nbr]) {
                parent[nbr] = node;
                dp[nbr] = 1 + dp[node];
                q.push(nbr);
            }
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }

    cout << dp[0] << nl;
    int node = 0;
    vector<int> ans;
    while (node != n - 1) {
        ans.push_back(node);
        node = parent[node];
    }
    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << n << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
