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

ll atleast_k(vi& a, int k) {
    int n = sz(a);
    int i = 0, j = 0;
    map<int, int> mp;
    ll ans = 0;
    while (j < n) {
        mp[a[j]]++;
        while (sz(mp) >= k) {
            ans += n - j;
            mp[a[i]]--;
            if (mp[a[i]] == 0) {
                mp.erase(a[i]);
            }
            i++;
        }
        j++;
    }
    return ans;
}

void solution_fn() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << (n * 1ll * (n + 1)) / 2 - atleast_k(a, k + 1) << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
