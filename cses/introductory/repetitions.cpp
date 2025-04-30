/* ***  METADATA
PROBLEM: introductory_repetitions__
ON: 2025-01-27
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
    string s;
    cin >> s;
    int n = sz(s);

    int count = 1, ans = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            count++;
            ans = max(ans, count);
        } else {
            count = 1;
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
