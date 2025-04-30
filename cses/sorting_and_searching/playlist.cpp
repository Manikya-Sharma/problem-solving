/* ***  METADATA
PROBLEM: sorting_and_searching_playlist__
ON: 2025-02-04
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

void solution_fn() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (auto& elem : a) {
        mp[elem] = -1;
    }
    int i = 0, j = 0;
    int ans = 0;
    while (j < n) {
        int next = a[j];
        if (mp[next] >= i) {
            i = mp[next] + 1;
        }
        ans = max(ans, j - i + 1);
        mp[next] = j;
        j++;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
