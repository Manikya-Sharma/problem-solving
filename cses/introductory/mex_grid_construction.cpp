/* ***
ON: 2025-06-29
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
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            set<int> st;
            for (int k = 0; k < i; k++) {
                st.insert(ans[k][j]);
            }
            for (int k = 0; k < j; k++) {
                st.insert(ans[i][k]);
            }
            if (st.empty()) {
                ans[i][j] = 0;
                continue;
            }
            for (int x = 0; x < n * n; x++) {
                if (!st.count(x)) {
                    ans[i][j] = x;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " \n"[j == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

