/* ***  METADATA
PROBLEM: sorting_and_searching_restaurant_customers__
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
    int n;
    cin >> n;
    vi start(n), end(n);
    for (int i = 0; i < n; i++) {
        cin >> start[i] >> end[i];
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int max_count = 0;
    int count = 0;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (start[i] < end[j]) {
            count++;
            i++;
        } else if (start[i] > end[j]) {
            j++;
            count--;
        } else {
            i++;
            j++;
        }
        max_count = max(max_count, count);
    }
    cout << max_count << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
