/*
[abc153] B - Common Raccoon vs Monster
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int H, N;
int A[MAX_N];

ll solve() {
    int s = 0;
    for (int i = 0; i < N; i++) {
        s += A[i];
    }
    return s >= H;
}

int main() {
    cin >> H >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
