/* ***  METADATA

ON: 2025-02-11
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
    vector<pair<int, int>> vpi(n);
    for (int i=0; i<n; i++) {
        cin >> vpi[i].first >> vpi[i].second;
    }
    sort(vpi.begin(), vpi.end());
    long long ans = 0;
    long long curr = 0;
    for (int i=0;i<n; i++) {
        curr += vpi[i].first;
        ans += vpi[i].second-curr;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}


