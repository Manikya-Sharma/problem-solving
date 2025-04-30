/* ***
ON: 2025-03-14
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
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> color(n, -1);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (color[i] != -1)
            continue;
        color[i] = 0;
        q.push(i);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int exp = !color[node];
            for (auto& nbr : adj[node]) {
                if (color[nbr] != -1 && color[nbr] != exp) {
                    cout << "IMPOSSIBLE" << nl;
                    return;
                }
                if (color[nbr] != -1)
                    continue;
                color[nbr] = exp;
                q.push(nbr);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << (color[i] == -1 ? 1 : color[i] + 1) << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

