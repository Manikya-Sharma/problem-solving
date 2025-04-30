/* ***  METADATA
PROBLEM: introductory_gray_code
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

int gray(int n) {
    int res = 0;
    for (int i = 0; i < 30; i++) {
        res |= (((n & (1 << i)) >> i) ^ ((n & (1 << (i + 1))) >> (i + 1))) << i;
    }
    return res;
}

void solution_fn() {
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        int res = gray(i);
        for (int j = n - 1; j >= 0; j--) {
            cout << ((res & (1 << j)) >> j);
        }
        cout << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
