/* ***
ON: 2025-03-13
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

class DSU {
    vector<int> parent;
    vector<int> size;

   public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (size[a] > size[b])
            swap(a, b);
        parent[a] = b;
        size[b] += size[a];
    }

    int find(int a) {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }
};

void solution_fn() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a - 1, b - 1};
    }
    DSU dsu(n);
    for (auto& [x, y] : edges) {
        dsu.merge(x, y);
    }
    set<int> st;
    vector<pair<int, int>> roads;
    st.insert(dsu.find(0));
    for (int i = 1; i < n; i++) {
        int par = dsu.find(i);
        if (!st.count(par)) {
            roads.push_back({*st.begin(), par});
            st.insert(par);
        }
    }
    cout << sz(roads) << nl;
    for (auto& [x, y] : roads) {
        cout << x + 1 << " " << y + 1 << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
