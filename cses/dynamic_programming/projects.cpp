/* ***
ON: 2025-03-19
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
    // score -> start -> end
    vector<pair<ll, pair<int, int>>> vpi(n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vpi[i] = {c, {a, b}};
    }
    auto comp = [](pair<ll, pair<int, int>>& p1,
                   pair<ll, pair<int, int>>& p2) {
        return p1.second.second < p2.second.second;
    };
    sort(vpi.begin(), vpi.end(), comp);
    vector<ll> dp(n);
    dp[0] = vpi[0].first;
    for (int i = 1; i < n; i++) {
        // find the latest day which can be considered
        int start = 0, end = i - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (vpi[mid].second.second < vpi[i].second.first) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if (end == -1) {
            dp[i] = max(dp[i - 1], vpi[i].first);
        } else {
            dp[i] = max(dp[i - 1], vpi[i].first + dp[end]);
        }
    }
    cout << dp[n - 1] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
