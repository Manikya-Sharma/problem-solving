/* ***  METADATA

ON: 2025-01-30
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
    string s;
    cin >> s;
    int n = sz(s);
    int freq[26] = {0};
    for (auto& ch : s) {
        freq[ch - 'A']++;
    }
    char odd_char = 0;
    string res(n, '#');
    int i = 0, j = n - 1;
    for (int k = 0; k < 26; k++) {
        char ch = char(k) + 'A';
        int f = freq[k];
        if (f % 2 == 1) {
            if (odd_char) {
                cout << "NO SOLUTION" << nl;
                return;
            }
            odd_char = ch;
            res[n / 2] = odd_char;
        }
        while (f > 1) {
            res[i++] = ch;
            res[j--] = ch;
            f -= 2;
        }
    }
    cout << res << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
