/* ***  METADATA

ON: 2025-02-12
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

template <class T = int>
class SparseTable {
    vector<vector<T>> table;
    function<T(T, T)> func;
    void preprocess(vector<T>& inp) {
        int n = sz(inp);
        for (int i = 0; i < n; i++) {
            table[i][0] = inp[i];
        }
        for (int i = 1; (1 << i) <= n; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                table[j][i] =
                    func(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

   public:
    SparseTable<T>(vector<T>& inp, function<T(T, T)> fn) : func(fn) {
        int n = sz(inp);
        int hbit = 32 - __builtin_clz(n);
        table.resize(n);
        for (int i = 0; i < n; i++) {
            table[i].resize(hbit);
        }
        preprocess(inp);
    }
    T query(int l, int r) {
        int t = r - l + 1;
        int k = 31 - __builtin_clz(t);
        T ans = func(table[l][k], table[r - (1 << k) + 1][k]);
        return ans;
    }
};

void solution_fn() {
    int n, x, y;
    cin >> n >> x >> y;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }
    auto comp = [](ll u, ll v) {
        return max(u, v);
    };
    SparseTable<ll> st(prefix, comp);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll res = st.query(i + x - 1, i + y - 1);
        ans = max(ans, res - a[i - 1]);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
