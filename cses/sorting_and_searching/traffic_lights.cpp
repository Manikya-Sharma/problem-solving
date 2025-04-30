/* ***  METADATA

ON: 2025-02-05
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
    int x, n;
    cin >> x >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> lights;
    lights.insert(0);
    lights.insert(x);
    multiset<int> gaps;
    gaps.insert(x);
    for (auto& light : a) {
        auto low = lights.upper_bound(light);
        auto high = low;
        low--;
        gaps.erase(gaps.find(*high - *low));
        lights.insert(light);
        gaps.insert(light - *low);
        gaps.insert(*high - light);
        cout << *(gaps.crbegin()) << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
