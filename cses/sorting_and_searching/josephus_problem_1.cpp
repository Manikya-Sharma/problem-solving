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

class Node {
   public:
    int val;
    Node* next;
    Node* prev;
    Node(int value) : val(value), next(nullptr), prev(nullptr) {}
};

void solution_fn() {
    int n;
    cin >> n;
    Node* root = new Node(1);
    Node* temp = root;
    for (int i = 1; i < n; i++) {
        Node* temp2 = new Node(i + 1);
        temp2->prev = temp;
        temp->next = temp2;
        temp = temp2;
    }
    temp->next = root;
    root->prev = temp;
    root = root->next;
    for (int i = 0; i < n; i++) {
        cout << root->val << " \n"[i == n - 1];
        root->prev->next = root->next;
        root->next->prev = root->prev;
        temp = root->next->next;
        delete root;
        root = temp;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
