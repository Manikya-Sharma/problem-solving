/* ***  METADATA
PROBLEM: sorting_and_searching_apartments__
ON: 2025-02-02
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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int count = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        int size = b[j];
        int low = a[i] - k;
        int high = a[i] + k;
        if (size >= low && size <= high) {
            count++;
            i++;
            j++;
        } else if (size < low) {
            j++;
        } else {
            i++;
        }
    }
    cout << count << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
