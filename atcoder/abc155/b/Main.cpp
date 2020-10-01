/*
[abc155] B - Papers, Please
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100;

int N;
int A[MAX_N];

bool solve() {
    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 0 && A[i] % 3 != 0 && A[i] % 5 != 0) return false;
    }

    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << (solve() ? "APPROVED" : "DENIED") << endl;

    return 0;
}
