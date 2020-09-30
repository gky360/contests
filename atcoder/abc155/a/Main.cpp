/*
[abc155] A - Poor
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int A[3];

bool solve() {
    sort(A, A + 3);

    return (A[0] == A[1] && A[1] != A[2]) || (A[0] != A[1] && A[1] == A[2]);
}

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
