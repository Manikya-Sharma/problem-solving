/* ***  METADATA
PROBLEM: sorting_and_searching_concert_tickets__
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
    int n, m;
    cin >> n >> m;
    multiset<int> a;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        a.insert(elem);
    }
    vi b(m);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (auto& max_price : b) {
        auto idx = a.upper_bound(max_price);
        if (idx == a.begin()) {
            cout << -1 << nl;
        } else {
            idx--;
            cout << *idx << nl;
            a.erase(idx);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
