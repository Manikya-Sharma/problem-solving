/* ***
ON: 2025-07-12
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

class SegTree {
    vector<ll> arr;
    int n;
    void build(vector<int> &inp, int l, int r, int idx) {
        if (l == r) {
            arr[idx] = inp[l];
            return;
        }
        int m = (l + r) / 2;
        build(inp, l, m, 2 * idx);
        build(inp, m + 1, r, 2 * idx + 1);
        arr[idx] = arr[2 * idx] + arr[2 * idx + 1];
    }

    ll _find(int l, int r, int _l, int _r, int idx) {
        if (l > r)
            return 0;
        if (_l == l && _r == r)
            return arr[idx];
        int _m = (_l + _r) / 2;
        return _find(l, min(r, _m), _l, _m, 2 * idx) +
               _find(max(l, _m + 1), r, _m + 1, _r, 2 * idx + 1);
    }

  public:
    SegTree(vector<int> &inp) {
        n = (int)inp.size();
        arr.resize(4 * n);
        build(inp, 0, n - 1, 1);
    }
    ll find(int l, int r) { return _find(l, r, 0, n - 1, 1); }
};

void solution_fn() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegTree seg(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << seg.find(l - 1, r - 1) << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
