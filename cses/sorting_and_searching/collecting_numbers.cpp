/* ***  METADATA
PROBLEM: sorting_and_searching_collecting_numbers__
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
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        a[elem] = i;
    }
    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (a[i + 1] < a[i]) {
            rounds++;
        }
    }
    cout << rounds << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
