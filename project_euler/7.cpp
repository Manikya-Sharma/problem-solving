/* ***
ON: 2025-04-27
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

#define SIZE (int)(2e5)

void solution_fn(bool sieve[]) {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 2; i < SIZE; i++) {
        if (!sieve[i]) {
            count++;
        }
        if (count == n) {
            cout << i << nl;
            return;
        }
    }
    assert(false);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_cases;
    cin >> test_cases;
    bool sieve[SIZE] = {false};
    sieve[1] = true;
    for (int i = 2; i < SIZE; i++) {
        if (sieve[i])
            continue;
        for (ll j = i; j * i < SIZE; j++) {
            sieve[j * i] = true;
        }
    }
    while (test_cases--) {
        solution_fn(sieve);
    }
    return 0;
}

