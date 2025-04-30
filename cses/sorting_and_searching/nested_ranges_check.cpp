/* ***  METADATA
PROBLEM: sorting_and_searching_nested_ranges_check__
ON: 2025-02-09
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
    vector<tuple<int, int, int>> vpi(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vpi[i] = {a, b, i};
    }
    auto comp = [](tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
        if (get<0>(t1) == get<0>(t2)) {
            return get<1>(t1) > get<1>(t2);
        }
        return get<0>(t1) < get<0>(t2);
    };
    sort(vpi.begin(), vpi.end(), comp);
    vi contains(n, 0);
    vi is_in(n, 0);

    int min_end = 1e9 + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (get<1>(vpi[i]) >= min_end) {
            contains[get<2>(vpi[i])] = 1;
        }
        min_end = min(min_end, get<1>(vpi[i]));
    }

    int max_end = 0;
    for (int i = 0; i < n; i++) {
        if (get<1>(vpi[i]) <= max_end) {
            is_in[get<2>(vpi[i])] = 1;
        }
        max_end = max(max_end, get<1>(vpi[i]));
    }

    for (int i = 0; i < n; i++) {
        cout << contains[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << is_in[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
