/*
[agc010] D - Decrementing
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N;
int A[MAX_N];

int gcd(ll a, ll b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

bool solve() {
    int cnt_od = 0, od_i = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 1) {
            cnt_od++;
            od_i = i;
        }
    }
    if ((N - cnt_od) % 2 == 1) {
        return true;
    }
    if (cnt_od != 1 || A[od_i] == 1) {
        return false;
    }

    A[od_i]--;
    int g = A[0];
    for (int i = 1; i < N; i++) {
        g = gcd(g, A[i]);
    }
    for (int i = 0; i < N; i++) {
        A[i] /= g;
    }
    return !solve();
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << (solve() ? "First" : "Second") << endl;

    return 0;
}
