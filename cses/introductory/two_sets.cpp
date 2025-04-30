/* ***  METADATA

ON: 2025-01-29
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
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
    if (n % 4 == 0) {
        cout << n / 2 << nl;
        int i = 1, j = n;
        while (i <= n / 4) {
            cout << i << " " << j << " ";
            i++;
            j--;
        }
        cout << nl;
        cout << n / 2 << nl;
        while (i < j) {
            cout << i << " " << j << " ";
            i++;
            j--;
        }
    } else {
        cout << (n - 3) / 2 + 2 << nl;
        cout << "1 2 ";
        int i = 4, j = n;
        while (i < (n + 1) / 4 + 3) {
            cout << i << " " << j << " ";
            i++;
            j--;
        }
        cout << nl;
        cout << (n - 3) / 2 + 1 << nl;
        cout << "3 ";
        while (i < j) {
            cout << i << " " << j << " ";
            i++;
            j--;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
