/* *** PROBLEM: project_euler_2_even_fibonacci_numbers
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

class Matrix {
   public:
    vector<vector<ll>> arr;
    int n;
    Matrix(vector<vector<ll>> inp) : arr(inp) { n = sz(inp); }
    Matrix(int size) : n(size) {
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            arr[i].resize(n);
        }
    }
    static void matmul(Matrix& m1, Matrix& m2) {
        int n = sz(m1.arr);
        Matrix temp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ll sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += m1.arr[i][k] * m2.arr[k][j];
                }
                temp.arr[i][j] = sum;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m1.arr[i][j] = temp.arr[i][j];
            }
        }
    }
    static Matrix exp(Matrix& m, int n) {
        Matrix res({{1, 0}, {0, 1}});
        while (n) {
            if (n & 1) {
                matmul(res, m);
            }
            matmul(m, m);
            n >>= 1;
        }
        return res;
    }
};

void solution_fn() {
    ll ans = 0;
    int i = 1;
    while (true) {
        Matrix a({{1, 1}, {1, 0}});
        Matrix b({{2, 0}, {1, 0}});
        a = Matrix::exp(a, i - 1);
        Matrix::matmul(a, b);
        ll elem1 = a.arr[0][0];
        ll elem2 = a.arr[1][0];
        if (elem1 > 4000000) {
            break;
        }
        if (elem1 % 2 == 0)
            ans += elem1;
        if (elem2 > 4000000) {
            break;
        }
        if (elem2 % 2 == 0)
            ans += elem2;
        i += 2;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
