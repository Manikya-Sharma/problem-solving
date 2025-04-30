/* ***  METADATA
PROBLEM: sorting_and_searching_movie_festival__
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
    vector<pair<int, int>> vpi(n);
    for (int i = 0; i < n; i++) {
        cin >> vpi[i].first >> vpi[i].second;
    }
    auto comp = [](pair<int, int>& p1, pair<int, int>& p2) {
        if (p1.second == p2.second) {
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    };
    sort(vpi.begin(), vpi.end(), comp);
    int last_end = -1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (vpi[i].first >= last_end) {
            count++;
            last_end = vpi[i].second;
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
