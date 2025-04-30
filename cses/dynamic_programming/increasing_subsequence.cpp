/* ***
ON: 2025-03-10
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

void solution_fn() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> longest_sequence;
    longest_sequence.push_back(1e9 + 1);
    for (int i = 0; i < n; i++) {
        if (longest_sequence.back() >= a[i]) {
            // replace the rightmost value greater than or equal to a[i]
            int ub = lower_bound(longest_sequence.begin(),
                                 longest_sequence.end(), a[i]) -
                     longest_sequence.begin();
            if (ub == sz(longest_sequence))
                continue;
            longest_sequence[ub] = a[i];
        } else {
            longest_sequence.push_back(a[i]);
        }
    }
    cout << sz(longest_sequence) << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

