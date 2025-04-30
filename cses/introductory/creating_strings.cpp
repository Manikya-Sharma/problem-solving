/* ***  METADATA
PROBLEM: introductory_creating_strings__
ON: 2025-01-31
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

void solve(string& s, set<string>& ans, int idx) {
    int n = sz(s);
    if (idx == n) {
        ans.insert(s);
        return;
    }
    for (int i = idx; i < n; i++) {
        swap(s[i], s[idx]);
        solve(s, ans, idx + 1);
        swap(s[i], s[idx]);
    }
}

void solution_fn() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    set<string> ans;
    solve(s, ans, 0);
    cout << sz(ans) << nl;
    for (auto& str : ans) {
        cout << str << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
