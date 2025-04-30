/* ***
ON: 2025-03-15
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

bool is_palin(int num) {
    int temp = num;
    int rev = 0;
    while (num) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev == temp;
}

void solution_fn() {
    int ans = -1;
    for (int i = 100; i <= 999; i++) {
        for (int j = 100; j <= 999; j++) {
            int prod = i * j;
            if (is_palin(prod)) {
                ans = prod;
            }
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

