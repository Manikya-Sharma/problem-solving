/* ***  METADATA
PROBLEM: sorting_and_searching_sum_of_two_values__
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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    while (i < j) {
        ll sum = a[i].first + a[j].first;
        if (sum < x) {
            i++;
        } else if (sum > x) {
            j--;
        } else {
            cout << a[i].second + 1 << " " << a[j].second + 1 << nl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
