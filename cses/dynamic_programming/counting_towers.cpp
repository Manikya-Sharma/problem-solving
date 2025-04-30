/* ***  METADATA

ON: 2025-02-18
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

#define MOD (int)(1e9 + 7)

class Matrix {
   public:
    vector<vector<int>> arr;
    int n;
    Matrix(vector<vector<int>> inp) : arr(inp) { n = sz(inp); }
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
                int sum = 0;
                for (int k = 0; k < n; k++) {
                    sum = int((sum + m1.arr[i][k] * 1ll * m2.arr[k][j]) % MOD);
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
    int n;
    cin >> n;

    Matrix a({{2, 1}, {1, 4}});
    Matrix b({{1, 0}, {1, 0}});

    a = Matrix::exp(a, n - 1);
    Matrix::matmul(a, b);

    cout << (a.arr[0][0] + a.arr[1][0]) % MOD << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solution_fn();
    }
    return 0;
}
