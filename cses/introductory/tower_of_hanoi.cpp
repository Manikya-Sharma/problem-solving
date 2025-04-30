/* ***  METADATA
PROBLEM: introductory_tower_of_hanoi__
ON: 2025-01-31
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

void solve(int n, int start, int goal) {
    if (n == 0) {
        return;
    }
    solve(n - 1, start, 6 - (start + goal));
    cout << start << " " << goal << nl;
    solve(n - 1, 6 - (start + goal), goal);
}

void solution_fn() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << nl;
    solve(n, 1, 3);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
