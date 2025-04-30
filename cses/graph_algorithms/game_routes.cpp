/* ***
ON: 2025-04-03
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

#define MOD (int)(1e9 + 7)

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
    for (auto& [x, y] : edges) {
        adj[x].push_back(y);
    }
    vector<int> dp(n);
    dp[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (auto& nbr : adj[node]) {
            dp[nbr] = (dp[nbr] + dp[node]) % MOD;
            q.push(nbr);
        }
    }
    cout << dp[n - 1] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

