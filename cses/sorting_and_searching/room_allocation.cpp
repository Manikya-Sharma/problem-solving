/* ***  METADATA

ON: 2025-02-10
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
    sort(vpi.begin(), vpi.end());
    int curr_station = 1;
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;  //dept time to station mapping
    for (int i = 0; i < n; i++) {
        int arvtime = get<0>(vpi[i]);  // arrival of curr train
        int depttime = get<1>(vpi[i]);
        if (pq.size() && pq.top().first < arvtime) {
            int min_station = pq.top().second;
            pq.pop();
            mp[get<2>(vpi[i])] = min_station;
            pq.push({depttime, min_station});

        } else {
            mp[get<2>(vpi[i])] = curr_station;
            pq.push({depttime, curr_station});
            curr_station++;
        }
    }
    int maxstation = 0;
    for (auto it : mp) {
        maxstation = max(maxstation, it.second);
    }
    cout << maxstation << endl;

    for (int i = 0; i < n; i++) {
        cout << mp[i] << " ";
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
