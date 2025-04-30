/* ***  METADATA
PROBLEM: sorting_and_searching_collecting_numbers2__
ON: 2025-02-03
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
    int n, m;
    cin >> n >> m;
    vi v(n + 1);
    vi pos(n);
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        v[elem] = i;
        pos[i] = elem;
    }
    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (v[i + 1] < v[i]) {
            rounds++;
        }
    }
    for (int tt = 0; tt < m; tt++) {
        int x, y;
        cin >> x >> y;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
