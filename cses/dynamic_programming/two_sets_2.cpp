/* ***
ON: 2025-03-19
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
    int n;
    cin >> n;
    if (n * (n + 1) / 2 % 2 != 0) {
        cout << 0 << nl;
        return;
    }
    int target = n * (n + 1) / 4;
    vector<int> prev(target + 1, 0);
    for (int i = 1; i <= n; i++) {
        vector<int> curr(target + 1);
        if (i == 1)
            curr[0] = 1;
        for (int j = 0; j <= target; j++) {
            curr[j] = (curr[j] + prev[j]) % MOD;
            if (j - i >= 0) {
                curr[j] = (curr[j] + prev[j - i]) % MOD;
            }
        }
        prev = curr;
    }
    cout << prev[target] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

