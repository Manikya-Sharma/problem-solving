/* ***  METADATA
PROBLEM: introductory_chessboard_and_queens__
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

enum Cell { FREE, BLOCK, OCCUPY };

bool possible(Cell board[8][8], int x, int y) {
    for (int i = 0; i < y; i++) {
        if (board[x][i] == OCCUPY) {
            return false;
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < y; j++) {
            if (board[i][j] != OCCUPY)
                continue;
            if (abs(x - i) == abs(y - j))
                return false;
        }
    }
    return true;
}

ll solve(Cell board[8][8], int col) {
    if (col == 8) {
        return 1;
    }
    ll ways = 0;
    for (int i = 0; i < 8; i++) {
        if (board[i][col] == BLOCK || !possible(board, i, col)) {
            continue;
        }
        board[i][col] = OCCUPY;
        ways += solve(board, col + 1);
        board[i][col] = FREE;
    }
    return ways;
}

void solution_fn() {
    Cell board[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char elem;
            cin >> elem;
            if (elem == '.') {
                board[i][j] = FREE;
            } else {
                board[i][j] = BLOCK;
            }
        }
    }
    cout << solve(board, 0) << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
